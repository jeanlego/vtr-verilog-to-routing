`define ADDER_WIDTH %%ADDER_BITS%%
`define DUMMY_WIDTH 128

`define %%LEVELS_OF_ADDER%%_LEVEL_ADDER

module adder_tree_top (
	clk,
	isum0_0_0_0, isum0_0_0_1, isum0_0_1_0, isum0_0_1_1, 

`ifdef 3_LEVEL_ADDER
	isum0_1_0_0, isum0_1_0_1, isum0_1_1_0, isum0_1_1_1,
`endif

	sum,
);
	input clk;
	input [`ADDER_WIDTH-1:0] isum0_0_0_0, isum0_0_0_1, isum0_0_1_0, isum0_0_1_1;

`ifdef 3_LEVEL_ADDER
	input [`ADDER_WIDTH-1:0] isum0_1_0_0, isum0_1_0_1, isum0_1_1_0, isum0_1_1_1;
	wire [`ADDER_WIDTH-1:0] sum0_0_0, sum0_0_1, sum0_1_0, sum0_1_1;
`endif

	output [`ADDER_WIDTH-1:0] sum;

	wire [`ADDER_WIDTH-1:0] sum0;
	wire [`ADDER_WIDTH-1:0] sum0_0, sum0_1;


	assign sum0 = sum0_0 %%OPERATOR%% sum0_1;

`ifdef 3_LEVEL_ADDER
	assign sum0_0_0 = isum0_0_0_0 %%OPERATOR%% isum0_0_0_1;
	assign sum0_0_1 = isum0_0_1_0 %%OPERATOR%% isum0_0_1_1;	
	assign sum0_1_0 = isum0_1_0_0 %%OPERATOR%% isum0_1_0_1;
	assign sum0_1_1 = isum0_1_1_0 %%OPERATOR%% isum0_1_1_1;
	
	assign sum0_0 = sum0_0_0 %%OPERATOR%% sum0_0_1;
	assign sum0_1 = sum0_1_0 %%OPERATOR%% sum0_1_1;
`endif

`ifdef 2_LEVEL_ADDER
	assign sum0_0 = isum0_0_0_0 %%OPERATOR%% isum0_0_0_1;
	assign sum0_1 = isum0_0_1_0 %%OPERATOR%% isum0_0_1_1;
`endif

	always @(posedge clk) begin
			sum <= sum0;
	end

endmodule
