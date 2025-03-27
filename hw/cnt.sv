// Copyright 2024 Politecnico di Torino.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 2.0 (the "License"); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-2.0. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.
//
// File: cnt.sv
// Author(s):
//   Luigi Giuffrida
//   Michele Caon
// Date: 08/11/2024
// Description: Simple up counter with programmable threshold

module cnt #(
  // Counter bitwidth
  parameter int W = 16
) (
  input logic clk_i,
  input logic rst_ni,

  input  logic         en_i,      // counter enable
  input  logic         clr_i,     // reset counter to zero
  input  logic         ld_i,      // counter load
  input  logic [W-1:0] ld_val_i,  // value to load
  input  logic [W-1:0] thr_i,     // counter threshold
  output logic [W-1:0] cnt_o,     // current counter value
  output logic         tc_o       // threshold crossed
);
  // INTERNAL SIGNALS
  logic [W-1:0] cnt_val;  // current counter value
  logic         tc;  // terminal count
  logic [W-1:0] ciclos_nivel_alto;  
  logic [W-1:0] ciclos_nivel_bajo;
  logic update_nivel_bajo;

  // La idea es modificar el contador, para que en lugar de hacer una interrupcion ala salida, genere una señal PWM configurable
  // Para no cambiar los nombres, se utilizara la señal tc_o para generar la señal PWM
  // La señal ld_val_i se utilizara para configurar el ciclo de trabajo de la señal PWM
  // La señal thr_i se utilizara para configurar el periodo de la señal PWM

  // COUNTER LOGIC
  always_ff @(posedge clk_i or negedge rst_ni) begin  // asynchronous reset
    if (!rst_ni) cnt_val <= 'h0;
    else begin  // synchronous clear and count
      if (clr_i) begin
        // Por defecto, la señal PWM es de un periodo de 10 ciclos y un ciclo de trabajo de 0
        ciclos_nivel_alto <= 'hA;
        ciclos_nivel_bajo <= 'h0;
        cnt_val <= 'h0;
        update_nivel_bajo <= 0;
      end
      else if (ld_i) begin
        // Para facilitar el diseño, la señal thr_i es el numero de ciclos del periodo de la señal PWM
        // Para configurar el ciclo de trabajo de la señal PWM, se utiliza la señal ld_val_i
        // ejemplo: 
        // thr_i = 10, la señal PWM tendra un periodo de 10 ciclos
        // ld_val_i = 50, la señal PWM tendra un ciclo de trabajo de 5 ciclos
        // Para hacer un redondeo, se utuliza un factor de 50 antes de dividir: 
        // si thr_i = 4 y ld_val_i = 49: 4 * 49 / 100 = 1, pero si se aplica el redondeo:
        // (4 * 49) + 50 / 100 = 2 
        /* Al ser asignaciuones no bloqueantes, es necesario crear un segundo ciclo para actualizar el valor dl nivel*/
        ciclos_nivel_alto <= (((ld_val_i * thr_i) + 50) / 100);
        update_nivel_bajo <= 1;
      end
      else if (update_nivel_bajo) begin
        update_nivel_bajo <= 0;
        ciclos_nivel_bajo <= thr_i - ciclos_nivel_alto;
      end
      else if (en_i) begin
        if (tc) begin
          if (cnt_val == ciclos_nivel_alto) begin
            tc <= 0;
            cnt_val <= 'h0;
          end
          else if (ciclos_nivel_bajo > 0) cnt_val <= cnt_val + 'h1;     
        end
        else begin
          if (cnt_val == ciclos_nivel_bajo) begin
            tc <= 1;
            cnt_val <= 'h0;
          end
          else if (ciclos_nivel_alto > 0) cnt_val <= cnt_val + 'h1;   
        end
      end
    end
  end

  //assign tc    = (cnt_val == thr_i);

  // OUTPUT ASSIGNMENTS
  assign cnt_o = cnt_val;
  assign tc_o  = tc;
endmodule
