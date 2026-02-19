//COSC 130
//Extra credit
//Dai'zjon Carney
#include <cstdio>
#include <fstream>
using namespace std;
// used a struct since it had public members that can be accessed from main.
// had int holder to hold the whole line of instruction
// used the other ints to hold their respective values
// used strings that have a similar purpose 
struct blah{
	int holder, rd, rs1, rs2, imm;
	string rss1, rss2, rd2, word;
};	
//declared a function that will ultimately be used to figure out abi registers
string convert(int abi);
int main(int argc, char *argv[]){
	FILE *fin,*fout;
	int filesize,realsize;
	unsigned int long opco, funct3;
//checks to see if the right amount of arguments are entered, and fails if not.
	if (argc != 3 and argc!= 4){
		printf("incorrect number of arguments \n");
		return -1;
	}
//opens and reads the binary file as well as error checks it.
	fin = fopen(argv[1], "rb"); //rb
	if (fin == nullptr){
		printf("error, file did not open \n");
		return -1;
	}
//checks if the second user argument  entered is - and writes to stdout if so.
//if not writes to file
	if(argv[2][0] =='-')
		fout = stdout;
	else{
			fout = fopen(argv[2],"w");
			if (fout == nullptr){
				printf("error \n");
				return -1;
			}
	}

//getting size of file

	fseek(fin, 0, SEEK_END);
	filesize = ftell(fin);
//each instruction is 4 bytes, so divided filesize by 4
	realsize = (filesize/4);
	fseek(fin, 0, SEEK_SET);
//created a for loop to ultimately read the insturctions of a binary file into an array
//each instruction is four bytes so reads four bytes in 
	blah *instruct = new blah[realsize];

	for(int i= 0; i < realsize; i++){
		fread(&instruct[i].holder,1,4,fin);
			
	}

	fclose(fin);
//user specified abi names or didn't therefore abi by default

	string ope;
	if (argc == 4)
		ope = argv[3][0];
	else
		ope = "a";
	


// performed a set of operations for abi registers
//Most processes are the same for the x registers so will be explaining those things only once
//used if statement to determine if we were using abi registers
//inside that if did a for loop to make i increase until it's one less than the real size
//Then did a nested switch that compares the opcode to the cases of opcode
	if(ope == "a"){	
	for(int i = 0; i < realsize; i++){
		opco = instruct[i].holder & 0x7f;
		funct3 = (instruct[i].holder >>12) & 0x7;
		switch (opco){
		//shifted and anded to get values of rd rs1 imm
			case 0b0010011://addi slli xori ori andi srli srai
			instruct[i].rd = (instruct[i].holder >> 7) & 0x1f;
			instruct[i].rs1 = (instruct[i].holder >> 15) & 0x1f;
			instruct[i].imm = instruct[i].holder >> 20;
//compares the funct 3 with the cases of funct 3 to figure out what instruction and saves it to word
			switch(funct3){
				case 0b000: //addi
						instruct[i].word = "addi";
					break;
				case 0b001: //slli
					instruct[i].word = "slli";
					break;
				case 0b100: //xori
						instruct[i].word = "xori";
					break;

				case 0b110: //ori
						instruct[i].word = "ori";
					break;
				case 0b111: //andi
						instruct[i].word = "andi";	
					break;
// sometimes instructions will have same opcode and funct3 so finds out which it is by seeing if the imm is 0
				case 0b101: //srli and srai
					if((instruct[i].imm >>5) == 0){
						instruct[i].word= "slri";
					}
					else{
						instruct[i].word = "srai";
						instruct[i].imm = (instruct[i].imm & 0x1f);
					}

					break;
// prints error message incase the instruction given had the same opcode but  didn't match funct3 (also for instructions that aren't implemented)

					default:
	
					if(fout == stdout){
					printf("inv	  invalid");
					}
					else{
						fprintf(fout,"inv	invalid");
					}
					break;
			}
// used if statements to know where to print to
//if fout was specified as stdout prints results to it. If not, prints it to file
//printed in the format the respective instuction needed, for example the .rd and .rs1 have x's infront of them while lui only the .rd has an x in front
	
		instruct[i].rd2 = convert(instruct[i].rd);
		instruct[i].rss1 = convert(instruct[i].rs1);
				if(fout == stdout){
				printf("%s ", instruct[i].word.c_str());
				printf(" %s, %s, %d\n", instruct[i].rd2.c_str(), instruct[i].rss1.c_str(), instruct[i].imm);
				}
				else{
				
				
				fprintf(fout,"%s ", instruct[i].word.c_str());
				fprintf(fout, "%s, %s, %d\n", instruct[i].rd2.c_str(), instruct[i].rss1.c_str(), instruct[i].imm);
				}
	

				break;
	//shifted and anded to find values of imm rd and word
			case 0b0110111://lui		
				instruct[i].imm = instruct[i].holder >> 12;
				instruct[i].imm = instruct[i].imm << 12;
				instruct[i].rd = ((instruct[i].holder >> 7) & 0x1f);
				instruct[i].word = "lui";

				
		instruct[i].rd2 = convert(instruct[i].rd);
				if(fout == stdout){
				printf("%s ", instruct[i].word.c_str());
				printf(" %s, %d\n", instruct[i].rd2.c_str(), instruct[i].imm);
				}
				else{
				
				
				fprintf(fout,"%s ", instruct[i].word.c_str());
				fprintf(fout, "%s, %d\n", instruct[i].rd2.c_str(), instruct[i].imm);
				}
				break;
			case 0b0100011: //sb sh sw sd
		
			instruct[i].rs1 = ((instruct[i].holder >> 15) & 0x1f);
			instruct[i].rs2 = ((instruct[i].holder >> 20) & 0x1f);
			instruct[i].imm = instruct[i].holder >> 25;
			instruct[i].imm = ((instruct[i].imm << 5) | ((instruct[i].holder >> 7) & 0x1f));
			
				switch(funct3){ 
		
					case 0b000: //sb
							
							instruct[i].word = "sb";

						break;

					case 0b001: //sh

							instruct[i].word = "sh";
						break;

					case 0b010: //sw

							instruct[i].word = "sw";
						break;

					case 0b011: //sd

							instruct[i].word = "sd";
						break;

					default:	
					if(fout == stdout){
					printf("inv		invalid");
					}
					else{
						fprintf(fout,"inv	invalid");
					}
					break;
				}
						

		instruct[i].rss2 = convert(instruct[i].rs2);
		instruct[i].rss1 = convert(instruct[i].rs1);
				if(fout == stdout){
				printf("%s ", instruct[i].word.c_str());
				printf(" %s, %d(%s)\n", instruct[i].rss2.c_str(),instruct[i].imm, instruct[i].rss1.c_str());
				}
				else{
				
				
				fprintf(fout,"%s ", instruct[i].word.c_str());
				
				fprintf(fout,"%s, %d(%s)\n", instruct[i].rss2.c_str(),instruct[i].imm, instruct[i].rss1.c_str());
				}
		
				break;
			case 0b0110011: //sra add xor srl sub sll or and
			
			instruct[i].rd = (instruct[i].holder >> 7) & 0x1f;
			instruct[i].rs1 = (instruct[i].holder >> 15) & 0x1f;
			instruct[i].rs2 = ((instruct[i].holder >> 20) & 0x1f);
			instruct[i].imm = instruct[i].holder >> 25;

			switch(funct3){

					case 0b000: //sub add


						if((instruct[i].imm >> 5) == 0){

							instruct[i].word = "add";
						}

						else{

							instruct[i].word = "sub";
						}


						break;
					
					case 0b100: //xor

						instruct[i].word = "xor";

						break;

					case 0b001: //sll

						instruct[i].word = "sll";

						break;

					case 0b101: //srl sra

							
						if((instruct[i].imm >> 5) == 0){

							instruct[i].word = "srl";
						}

						else{

							instruct[i].word = "sra";
						}

				
					break;

					case 0b111: //and

						instruct[i].word = "and";

					break;

					case 0b110: //or	

						instruct[i].word = "or";

					break;

					default:
					if(fout == stdout){
					printf("inv	  invalid");
					}
					else{
						fprintf(fout,"inv	invalid");
					}
					break;
			}
			
				
		instruct[i].rd2 = convert(instruct[i].rd);
		instruct[i].rss2 = convert(instruct[i].rs2);
		instruct[i].rss1 = convert(instruct[i].rs1);
				if(fout == stdout){
				printf("%s ", instruct[i].word.c_str());
				printf(" %s, %s, %s\n", instruct[i].rd2.c_str(),instruct[i].rss1.c_str(), instruct[i].rss2.c_str());
				}
				else{
				
				
				fprintf(fout,"%s ", instruct[i].word.c_str());
				
				fprintf(fout,"%s, %d(%s)\n", instruct[i].rss2.c_str(),instruct[i].imm, instruct[i].rss1.c_str());
				}
	

				break;
			case 0b1101111: // jal
				break;
			case 0b1100111: //jalr
			instruct[i].rd = (instruct[i].holder >> 7) & 0x1f;
			instruct[i].rs1 = (instruct[i].holder >> 15) & 0x1f;
			instruct[i].imm = instruct[i].holder >> 20;
			instruct[i].word = "jalr";

			
		instruct[i].rd2 = convert(instruct[i].rd);
		instruct[i].rss1 = convert(instruct[i].rs1);
				if(fout == stdout){
				printf("%s ", instruct[i].word.c_str());
				printf(" %s, %s, %d\n", instruct[i].rd2.c_str(),instruct[i].rss1.c_str(), instruct[i].imm);
				}
				else{
				
				
				fprintf(fout,"%s ", instruct[i].word.c_str());
				
				fprintf(fout,"%s,%s ,%d\n", instruct[i].rd2.c_str(),instruct[i].rss1.c_str(), instruct[i].imm);
				}
				break;
			case 0b0000011: //lb lh lw ld lwu
				
			instruct[i].rd = (instruct[i].holder >> 7) & 0x1f;
			instruct[i].rs1 = (instruct[i].holder >> 15) & 0x1f;
			instruct[i].imm = instruct[i].holder >> 20;
	//used a switch within this case to match each instruction with their proper funct3
			switch(funct3){

				case 0b000://lb
					instruct[i].word = "lb";
					break;
				case 0b001: //lh
					instruct[i].word = "lh";
					break;
				case 0b010: //lw
					instruct[i].word = "lw";
					break;
				case 0b110: //lwu
					instruct[i].word = "lwu";
					break;
				case 0b011: //ld
					instruct[i].word = "ld";
					break;
	
				default:
		
					if(fout == stdout){
					printf("inv		invalid");
					}
					else{
						fprintf(fout,"inv	invalid");
					}
					break;
			}
			

			if(fout == stdout){
				printf("%s ", instruct[i].word.c_str());
				printf("x%d, %d(x%d) \n", instruct[i].rd, instruct[i].imm, instruct[i].rs1);
				}
			else{
				
				
				fprintf(fout, "%s ", instruct[i].word.c_str());
				fprintf(fout, "x%d, %d(x%d) \n", instruct[i].rd, instruct[i].imm, instruct[i].rs1);
				}
		
				break;
			case 0b0011011: //slliw srliw sraiw
				
			instruct[i].rd = (instruct[i].holder >> 7) & 0x1f;
			instruct[i].rs1 = (instruct[i].holder >> 15) & 0x1f;
			instruct[i].imm = instruct[i].holder >> 25;
	//used a switch within this case to match each instruction with their proper funct3
			switch(funct3){

				case 0b001://slliw
					instruct[i].word = "slliw";
					break;
				case 0b101: //srliw sraiw
					instruct[i].word = "srliw";
					if((instruct[i].imm >>5) == 0){ 
						instruct[i].word = "srliw";
					}
					else{
						 instruct[i].word = "sraiw";
				
					}
					break;
				default:
			
					if(fout == stdout){
					printf("inv		invalid");
					}
					else{
						fprintf(fout,"inv	invalid");
					}
					break;
					
			}
				

		instruct[i].rd2 = convert(instruct[i].rd);
		instruct[i].rss1 = convert(instruct[i].rs1);
				if(fout == stdout){
				printf("%s ", instruct[i].word.c_str());
				printf(" %s,  %d(%s)\n", instruct[i].rd2.c_str(),instruct[i].imm, instruct[i].rss1.c_str());
				}
				else{
				
				
				fprintf(fout,"%s ", instruct[i].word.c_str());
				
				fprintf(fout,"%s, %d(%s)\n", instruct[i].rd2.c_str(),instruct[i].imm, instruct[i].rss1.c_str());
				}
		
	
				break;

			default:
				
					if(fout == stdout){
					printf("inv   invalid");
					}
					else{
						fprintf(fout,"inv	invalid");
					}
				break;



		}
	}

	}
		
	
//used an if statment to see if the user specified x registers
//used the same for loop for the same purpose as in abi
//compared opcode and funct3 to cases.
	if(ope == "x"){
	for(int i = 0; i < realsize; i++){
		opco = instruct[i].holder & 0x7f;
		funct3 = (instruct[i].holder >>12) & 0x7;
		switch (opco){
		
			case 0b0010011://addi slli xori ori andi srli srai
			instruct[i].rd = (instruct[i].holder >> 7) & 0x1f;
			instruct[i].rs1 = (instruct[i].holder >> 15) & 0x1f;
			instruct[i].imm = instruct[i].holder >> 20;

			switch(funct3){
				case 0b000: //addi
						instruct[i].word = "addi";
					break;
				case 0b001: //slli
					instruct[i].word = "slli";
					break;
				case 0b100: //xori
						instruct[i].word = "xori";
					break;

				case 0b110: //ori
						instruct[i].word = "ori";
					break;
				case 0b111: //andi
						instruct[i].word = "andi";	
					break;

				case 0b101: //srli and srai
					if((instruct[i].imm >>5) == 0){
						instruct[i].word= "slri";
					}
					else{
						instruct[i].word = "srai";
						instruct[i].imm = (instruct[i].imm & 0x1f);
					}

					break;
				
					default:
		
					if(fout == stdout){
					printf("inv	  invalid");
					}
					else{
						fprintf(fout,"inv	invalid");
					}
					break;
			}
		
				if(fout == stdout){
				printf("%s ", instruct[i].word.c_str());
				printf("x%d, x%d, %d\n", instruct[i].rd, instruct[i].rs1, instruct[i].imm);
				}
				else{
				
				
				fprintf(fout, "%s ", instruct[i].word.c_str());
				fprintf(fout, "x%d, x%d, %d\n", instruct[i].rd, instruct[i].rs1,instruct[i].imm );
				}


	
				break;
			case 0b0110111://lui		
				instruct[i].imm = instruct[i].holder >> 12;
				instruct[i].imm = instruct[i].imm << 12;
				instruct[i].rd = ((instruct[i].holder >> 7) & 0x1f);
				instruct[i].word = "lui";

				if(fout == stdout){
				printf("%s ", instruct[i].word.c_str());
				printf("x%d, %d \n", instruct[i].rd, instruct[i].imm);
				}
				else{
				
				
				fprintf(fout, "%s ", instruct[i].word.c_str());
				fprintf(fout, "x%d, %d \n", instruct[i].rd, instruct[i].imm);
				}
				break;
			case 0b0100011: //sb sh sw sd
		
			instruct[i].rs1 = ((instruct[i].holder >> 15) & 0x1f);
			instruct[i].rs2 = ((instruct[i].holder >> 20) & 0x1f);
			instruct[i].imm = instruct[i].holder >> 25;
			instruct[i].imm = ((instruct[i].imm << 5) | ((instruct[i].holder >> 7) & 0x1f));
			
				switch(funct3){ 
		
					case 0b000: //sb
							
							instruct[i].word = "sb";

						break;

					case 0b001: //sh

							instruct[i].word = "sh";
						break;

					case 0b010: //sw

							instruct[i].word = "sw";
						break;

					case 0b011: //sd

							instruct[i].word = "sd";
						break;

					default:
		
					if(fout == stdout){
					printf("inv	  invalid");
					}
					else{
						fprintf(fout,"inv	invalid");
					}
					break;
				}
	
				if(fout == stdout){
				printf("%s ", instruct[i].word.c_str());
				printf("x%d, %d(x%d)\n", instruct[i].rs2, instruct[i].imm, instruct[i].rs1);
				}
				else{
				
				
				fprintf(fout, "%s ", instruct[i].word.c_str());
				fprintf(fout, "x%d, %d(x%d)\n", instruct[i].rs2, instruct[i].imm,instruct[i].rs1 );
				}
			

				break;
			case 0b0110011: //sra add xor srl sub sll or and
			
			instruct[i].rd = (instruct[i].holder >> 7) & 0x1f;
			instruct[i].rs1 = (instruct[i].holder >> 15) & 0x1f;
			instruct[i].rs2 = ((instruct[i].holder >> 20) & 0x1f);
			instruct[i].imm = instruct[i].holder >> 25;

			switch(funct3){

					case 0b000: //sub add


						if((instruct[i].imm >> 5) == 0){

							instruct[i].word = "add";
						}

						else{

							instruct[i].word = "sub";
						}


						break;
					
					case 0b100: //xor

						instruct[i].word = "xor";

						break;

					case 0b001: //sll

						instruct[i].word = "sll";

						break;

					case 0b101: //srl sra

							
						if((instruct[i].imm >> 5) == 0){

							instruct[i].word = "srl";
						}

						else{

							instruct[i].word = "sra";
						}

				
					break;

					case 0b111: //and

						instruct[i].word = "and";

					break;

					case 0b110: //or	

						instruct[i].word = "or";

					break;

					default:
					if(fout == stdout){
					printf("inv		invalid");
					}
					else{
						fprintf(fout,"inv	invalid");
					}
					break;
			}
	
				if(fout == stdout){
				printf("%s ", instruct[i].word.c_str());
				printf("x%d, x%d, x%d\n", instruct[i].rd, instruct[i].rs1, instruct[i].rs2);
				}
				else{
				
				
				fprintf(fout, "%s ", instruct[i].word.c_str());
				fprintf(fout, "x%d, x%d, x%d\n", instruct[i].rd, instruct[i].rs1,instruct[i].rs2 );
				}
		
		

				break;
			case 0b1101111: // jal thats not complete
				break;
			case 0b1100111: //jalr
			instruct[i].rd = (instruct[i].holder >> 7) & 0x1f;
			instruct[i].rs1 = (instruct[i].holder >> 15) & 0x1f;
			instruct[i].imm = instruct[i].holder >> 20;
			instruct[i].word = "jalr";

			if(fout == stdout){
				printf("%s ", instruct[i].word.c_str());
				printf("x%d, x%d, %d \n", instruct[i].rd, instruct[i].rs1, instruct[i].imm);
				}
			else{
				
				
				fprintf(fout, "%s ", instruct[i].word.c_str());
				fprintf(fout, "x%d, x%d, %d \n", instruct[i].rd, instruct[i].rs1, instruct[i].imm);
				}
				break;
			case 0b0000011: //lb lh lw ld lwu
				
			instruct[i].rd = (instruct[i].holder >> 7) & 0x1f;
			instruct[i].rs1 = (instruct[i].holder >> 15) & 0x1f;
			instruct[i].imm = instruct[i].holder >> 20;
	//used a switch within this case to match each instruction with their proper funct3
			switch(funct3){

				case 0b000://lb
					instruct[i].word = "lb";
					break;
				case 0b001: //lh
					instruct[i].word = "lh";
					break;
				case 0b010: //lw
					instruct[i].word = "lw";
					break;
				case 0b110: //lwu
					instruct[i].word = "lwu";
					break;
				case 0b011: //ld
					instruct[i].word = "ld";
					break;
	
				default:
	
					if(fout == stdout){
					printf("inv		invalid");
					}
					else{
						fprintf(fout,"inv	invalid");
					}
					break;
			}
			

			if(fout == stdout){
				printf("%s ", instruct[i].word.c_str());
				printf("x%d, %d(x%d) \n", instruct[i].rd, instruct[i].imm, instruct[i].rs1);
				}
			else{
				
				
				fprintf(fout, "%s ", instruct[i].word.c_str());
				fprintf(fout, "x%d, %d(x%d) \n", instruct[i].rd, instruct[i].imm, instruct[i].rs1);
				}
		

				break;
			case 0b0011011: //slliw srliw sraiw
				
			instruct[i].rd = (instruct[i].holder >> 7) & 0x1f;
			instruct[i].rs1 = (instruct[i].holder >> 15) & 0x1f;
			instruct[i].imm = instruct[i].holder >> 25;
	//used a switch within this case to match each instruction with their proper funct3
			switch(funct3){

				case 0b001://slliw
					instruct[i].word = "slliw";
					break;
				case 0b101: //srliw sraiw
					instruct[i].word = "srliw";
					if((instruct[i].imm >>5) == 0){ //may edit
						instruct[i].word = "srliw";
					}
					else{
						 instruct[i].word = "sraiw";
				
					}
					break;
				default:
			
					if(fout == stdout){
					printf("inv	  invalid");
					}
					else{
						fprintf(fout,"inv	invalid");
					}
				break;
					
			}
			
			if(fout == stdout){
				printf("%s ", instruct[i].word.c_str());
				printf("x%d, x%d, x%d \n", instruct[i].rd, instruct[i].rs1, instruct[i].imm);
				}
			else{
				
				
				fprintf(fout, "%s ", instruct[i].word.c_str());
				fprintf(fout, "x%d, %d, (x%d) \n", instruct[i].rd, instruct[i].imm, instruct[i].rs1);
				}
		
	
				break;
			
		
			default:
				
					if(fout == stdout){
					printf("inv		invalid");
					}
					else{
						fprintf(fout,"inv	invalid");
					}
				break;



		}
	}

	}
	//deletes memory
	//closed the output file
delete[]instruct;
fclose(fout);
return 0;
}
//function definition, compares values to abi registers and returns the registers
string convert(int abi){
string val;
	switch(abi){

		case 0:
			val = "zero";
			break;
		case 1:
			val = "ra";
			break;
		case 2:
			val = "sp";
			break;
		case 3: 
			val = "gp";
			break;
		case 4:
			val = "tp";
			break;
		case 5:
			val = "t0";
			break;
		case 6:
			val = "t1";
			break;
		case 7:
			val = "t2";
			break;
		case 8:
			val = "s0";
			break;
		case 9:
			val = "s1";
			break;
		case 10:
			val = "a0";
			break;
		case 11:
			val = "a1";
			break;
		case 12:
			val = "a2";
			break;
		case 13:
			val = "a3";
			break;
		case 14:
			val = "a4";
			break;
		case 15: 
			val = "a5";
			break;
		case 16: 
			val = "a6";
			break;
		case 17: 
			val = "a7";
			break;
		case 18:
			val = "s2";
			break;
		case 19:
			val = "s3";
			break;
		case 20:
			val = "s4";
			break;
		case 21:
			val = "s5";
			break;
		case 22:
			val = "s6";
			break;
		case 23:
			val = "s7";
			break;
		case 24:
			val = "s8";
			break;
		case 25:
			val = "s9";
			break;
		case 26:
			val = "s10";
			break;
		case 27:
			val = "s11";
			break;
		case 28:
			val = "t3";
			break;
		case 29:
			val = "t4";
			break;
		case 30:
			val = "t5";
			break;
		case 31:
			val = "t6";
			break;
	}
	return val;
}
