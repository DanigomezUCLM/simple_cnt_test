module cnt (
    input logic clk_i,
    input logic rst_ni,
    input logic en_i,

    input logic [31:0] cnt_i,

    output logic [31:0] cnt_o,
    output logic cnt_end_o
);

    logic [31:0] cnt_val;

    always_ff @(posedge clk_i or negedge rst_ni)
    begin
        if (~rst_ni)
            cnt_val <= 32'h0;
        else if (en_i)
            cnt_val <= cnt_val + 32'h1;
    end

    assign cnt_o = cnt_val;
    assign cnt_end_o = (cnt_val == cnt_i);

endmodule
