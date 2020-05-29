module simple_op(in,out);
    input in;
    output out;

    `define first

    `ifndef first
        assign out = in;
    `endif
endmodule 