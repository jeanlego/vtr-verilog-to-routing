/* pg 396 - synchronous DFF reset */

module bm_DL_Dff_w_synch_reset(D, Clock, Resetn, Q);
	input D, Clock, Resetn;
	output Q;
	reg Q;
	
	always @(posedge Clock)
		if (!Resetn)
			Q <= D;
		else 
			Q <= 0;
	
endmodule
