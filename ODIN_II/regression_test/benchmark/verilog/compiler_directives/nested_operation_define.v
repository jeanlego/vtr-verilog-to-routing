
`define operator not
`define OP(out,in) `operator(out,in);

module simple_op(a,b);
    input  a;
    output b;

    `OP(b,a)
endmodule
