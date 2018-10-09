module frequency_divide( 
	clk,
	reset,
	base_clk,
	re_clkdiv2,
	re_clkdiv4,
	re_clkdiv8,
	fe_clkdiv2,
	fe_clkdiv4,
	fe_clkdiv8
);
	/* input declaration */
	input clk; 
	input reset;
	/* output declaration */
	output base_clk;
	output re_clkdiv2;
	output re_clkdiv4;
	output re_clkdiv8;
	output fe_clkdiv2;
	output fe_clkdiv4;
	output fe_clkdiv8;

	/*  intermediate declaration */
	reg [2:0] re_counter;

	/* intermediate to output assignments */
	assign base_clk = clk;
	assign re_clkdiv2 = re_counter[0];
	assign re_clkdiv4 = re_counter[1];
	assign re_clkdiv8 = re_counter[2];

	always @(posedge clk)
	begin
		if (reset)
		begin
			re_counter <= 3'b000;
		end
		else
		begin
			case (re_counter)
				3'b000:  begin	re_counter <= 3'b001;	end
				3'b001:	 begin	re_counter <= 3'b010;	end
				3'b010:	 begin	re_counter <= 3'b011;	end
				3'b011:	 begin	re_counter <= 3'b100;	end
				3'b100:	 begin	re_counter <= 3'b101;	end
				3'b101:	 begin	re_counter <= 3'b110;	end
				3'b110:	 begin	re_counter <= 3'b111;	end
				default: begin	re_counter <= 3'b000;	end
			endcase
		end
	end

	/*  intermediate declaration */
	reg [2:0] fe_counter;

	/* intermediate to output assignments */
	assign fe_clkdiv2 = fe_counter[0];
	assign fe_clkdiv4 = fe_counter[1];
	assign fe_clkdiv8 = fe_counter[2];

	always @(negedge clk)
	begin
		if (reset)
		begin
			fe_counter <= 3'b000;
		end
		else
		begin
			case (fe_counter)
				3'b000:  begin	fe_counter <= 3'b001;	end
				3'b001:	 begin	fe_counter <= 3'b010;	end
				3'b010:	 begin	fe_counter <= 3'b011;	end
				3'b011:	 begin	fe_counter <= 3'b100;	end
				3'b100:	 begin	fe_counter <= 3'b101;	end
				3'b101:	 begin	fe_counter <= 3'b110;	end
				3'b110:	 begin	fe_counter <= 3'b111;	end
				default: begin	fe_counter <= 3'b000;	end
			endcase
		end
	end

endmodule
