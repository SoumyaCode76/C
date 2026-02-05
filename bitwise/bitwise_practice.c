#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>


typedef enum operation
{
	CHECK=0,
	SET,
	CLEAR,
	RETURN,
	TOGGLE
}operation;

typedef enum choice
{
	COUNT_SET_BITS = 0,
	COUNT_RESET_BITS,
	SWAP_ODD_EVEN,
	REVERSE_BITS,
	MANIPULATE_BITS
}choice;

// count set bits
uint8_t count_set_bits(uint32_t num)
{
	uint8_t number_of_set_bits = 0;
	while(num)
	{
		num = num & (num - 1);
		number_of_set_bits++;
	}
	return number_of_set_bits;
}

// count reset bits
uint8_t count_reset_bits(uint32_t num)
{
	uint8_t number_of_reset_bits = 0;
	num = ~num;
	while(num)
	{
		num = num & (num - 1);
		number_of_reset_bits++;
	}
	return number_of_reset_bits;
}

// swap odd even bits
uint32_t swap_even_odd_bits(uint32_t num)
{
	uint32_t even_mask = 0x55555555;
	uint32_t odd_mask = 0xAAAAAAAA;
	
	uint32_t swapped = ((num & even_mask) << 1) | ((num & odd_mask) >> 1);
	return swapped;
}

// reverse bits
uint32_t reverse_bits(uint32_t num)
{
	uint32_t reversed = 0;
	while(num)
	{
		reversed = (reversed << 1) | (num & 1);
		num >>= 1;
	}
	return reversed;
}
// bit manipulation
void manipulate_bits(uint32_t num, uint32_t *out, operation op)
{
	return;
}

int main(int argc, char * argv[])
{
	uint32_t num = 0;
	choice ch = 0;
	if(argc > 2)
	{
		num = atoi(argv[1]);
		ch = (choice)atoi(argv[2]);
		switch(ch)
		{
			case COUNT_SET_BITS:
			{
				printf("Number of set bits in %d: %d\n", num, count_set_bits(num));
			}
			break;
			case COUNT_RESET_BITS:
			{
				printf("Number of reset bits in %d: %d\n", num, count_reset_bits(num));
			}
			break;
			case SWAP_ODD_EVEN:
			{
				printf("Odd-even swapped of %d: %d\n", num, swap_even_odd_bits(num));
			}
			break;
			case REVERSE_BITS:
			{
				printf("Reversed bits number of %d: %d\n", num, reverse_bits(num));
			}
			break;
			case MANIPULATE_BITS:
			{
				if(argc > 3)
				{
					operation op = (operation)atoi(argv[3]);
					uint32_t output = 0;
					manipulate_bits(num, &output, op);
					printf("Output for %d from %d: %d\n", op, num, output); 	
				}
			}
			break;
			default:
				printf("Wrong choice!\n");
		}
	}
	else
	{
		printf("===============MENU==============\n");
		printf("./bitwise_practice <number to operate on> <choice> [<bit manipulation choice>]\n");
		printf("CHOICES: COUNT_SET_BITS (=0), COUNT_RESET_BITS(=1), SWAP_ODD_EVEN(=2), REVERSE_BITS(=3), MANIPULATE_BITS(=4)\n");
		printf("BIT MANIPULATION CHOICES: CHECK(=0), SET(=1), CLEAR(=1), RETURN(=2), TOGGLE(=3)\n");	
	}
	return 0;
}
