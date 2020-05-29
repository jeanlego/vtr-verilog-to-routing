module simple_op(in,out);
    input in;
    output out;

    `define firsts

    `ifdef first
        assign out = in;
    `endif
endmodule 