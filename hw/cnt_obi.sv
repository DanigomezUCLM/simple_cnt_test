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
// File: cnt_obi.sv
// Author(s):
//   Michele Caon
// Date: 07/11/2024
// Description: OBI bus wrapper for the simple counter

module cnt_obi #(
  parameter int unsigned W = 32  // counter bitwidth (max: 32)
) (
  input logic clk_i,
  input logic rst_ni,

  // OBI interface
  input  logic        bus_req_i,
  input  logic        bus_we_i,
  input  logic [ 3:0] bus_be_i,
  input  logic [31:0] bus_addr_i,
  input  logic [31:0] bus_wdata_i,
  output logic        bus_gnt_o,
  output logic        bus_rvalid_o,
  output logic [31:0] bus_rdata_o,

  // Terminal count interrupt
  output logic tc_int_o  // interrupt to host system
);
  // INTERNAL SIGNALS
  // ----------------
  // OBI request and response
  cnt_obi_pkg::obi_req_t         bus_req;  // from host system
  cnt_obi_pkg::obi_resp_t        bus_rsp;  // to host system

  // Registers <--> Hanrdware counter
  logic                          cnt_en;
  logic                          cnt_clr;
  logic                  [W-1:0] cnt_val;
  logic                   [31:0] cnt_val_ext;
  logic                   [31:0] cnt_thr;
  logic                          cnt_tc;

  // --------------
  // COUNTER MODULE
  // --------------
  // Counter instance
  cnt #(
    .W(W)
  ) u_cnt (
    .clk_i (clk_i),
    .rst_ni(rst_ni),
    .en_i  (cnt_en),
    .clr_i (cnt_clr),
    .thr_i (cnt_thr[W-1:0]),
    .cnt_o (cnt_val),
    .tc_o  (cnt_tc)
  );

  // Interrupt to host system
  assign tc_int_o = cnt_tc;

  // -----------------
  // CONTROL REGISTERS
  // -----------------
  // Bus request
  assign bus_req = '{
          req: bus_req_i,
          we: bus_we_i,
          be: bus_be_i,
          addr: bus_addr_i,
          wdata: bus_wdata_i
      };

  // Zero-extended counter value
  assign cnt_val_ext = {{32-W{1'b0}}, cnt_val};

  // Control registers
  cnt_control_reg u_cnt_control_reg (
    .clk_i    (clk_i),
    .rst_ni   (rst_ni),
    .req_i    (bus_req),
    .rsp_o    (bus_rsp),
    .cnt_val_i(cnt_val_ext),
    .cnt_tc_i (cnt_tc),
    .cnt_en_o (cnt_en),
    .cnt_clr_o(cnt_clr),
    .cnt_thr_o(cnt_thr)
  );

  // Bus response
  assign bus_gnt_o    = bus_rsp.gnt;
  assign bus_rvalid_o = bus_rsp.rvalid;
  assign bus_rdata_o  = bus_rsp.rdata;

  // ----------
  // ASSERTIONS
  // ----------
`ifndef SYNTHESIS
  initial begin
    assert (W > 0 && W <= 32)
    else $error("Counter width must be in [1,32]");
  end
`endif  /* SYNTHESIS */
endmodule
