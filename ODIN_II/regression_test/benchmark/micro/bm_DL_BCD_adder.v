/* Pg 287 - BCD adder */
`define BITS 4
module bm_DL_BCD_adder (Cin, X, Y, S, Cout, Z);

	input Cin;
	input [`BITS-1:0] X, Y;

	output [`BITS-1:0] S;
	output Cout;
	output [`BITS:0] Z;

	wire [`BITS:0] tmp;

	assign Z = X + Y + Cin;
	assign tmp = (Z[`BITS-1:0] < 4'b1010)? Z : (Z + 4'b0110);
	assign Cout = tmp[`BITS];
	assign S = tmp[`BITS-1:0];
	
endmodule
