module simple_op(
    clk,
    reset,
    a,
    out,
    clk_out
    );

    input   clk;
    input   reset;
    input   [1:0] a;

    output  out;
    output  clk_out;

    assign clk_out = clk;
    wire temp;
    wire not_rst;

    or a1(temp, a[0],a[1]);
    not n1(not_rst, reset);

    always @(posedge clk)
    begin
        out <= (not_rst)? temp: 1'b0;
    end
endmodule