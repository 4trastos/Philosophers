/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:45:54 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/09 12:59:33 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// 0123456789abcdef
// ---------------
// 000000000000000
// 012345678912345

#define	NONE	0x000	//0

#define	RED		0x001	//1
#define BLUE	0x002	//2
#define	GREEN	0x004	//4
#define	YELLOW	0x008	//8   8 + 64 = 72
#define	PINK	0x010	//16
#define	BLACK	0x020	//32

#define	TRES	0x040	//64
#define	CUATRO	0x080	//128
#define	CINCO	0x100	//256

	/* ************************************************** */
	/*         Color de coche y número de puertas         */
	/*                                                    */
	/*	...::: Un coche Amarillo y tiene 3 puertas :::... */
	/* ************************************************** */

/*
 * OR	|	e1	|	e2	|	s1
  ----------------------------
  		|	0	|	0	|	0
		|	1	|	0	|	1
		|	0	|	1	|	1
		|	1	|	1	|	1


//	YELLOW = 0x00001000	(8)
//	TRES   = 0x01000000	(64)
//	OR                  (+)
//	RESULT = 0x01001000	(72)


*/

void	print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bit;

	while (i >= 0)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
	write(1, "\n", 1);
}

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bit = 0;

	while (i > 0)
	{
		bit = bit * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (bit);
}

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

int main(void)
{
	unsigned char  octet = 9;
	printf("Reverse BITS: %hhu, %hhu\n", octet, reverse_bits(octet));
	unsigned char bits = (unsigned char)NULL;
	print_bits(bits);
	unsigned char bats = -128;
	print_bits(bats);
	unsigned char bots = 127;
	print_bits(bots);
	unsigned char swap = 'B';
	printf("Swap BITS: %hhu, %hhu\n", swap, swap_bits(swap));

	/* ********************************************************* */
	/* Desmostración de como desborda y se convierte en negativo */
	/* ********************************************************* */

	char c = 0;
	int f = 0;
	while (c <= 127 && f != 1)
	{
		printf("%d\n", c);
		if (c == -128)
			f++;
		c++;
	}

	printf("\n");
	
	/* ********************************************************* */
	/*    ...:::  Operación coche amarillo y 3 puertas  :::...   */
	/* ********************************************************* */
	
	printf("Amarillo y tres puertas es: %d\n", YELLOW | TRES);
	printf("Tres: %d\n", TRES);
	print_bits(TRES);
	return (0);
}
