#include "stdafx.h"
#include<iostream>
using namespace std;

void print_spiral(int m[][5], int row, int col)
{
	int layer_total = (col % 2) ? col : col / 2;
	for(int current_layer=0; current_layer<layer_total; current_layer++)
	{

		for (int i = current_layer; i < col-1; i++)
			cout << m[current_layer][i] << " ";
		

		for (int i = current_layer; i < row-1; i++)
			cout << m[i][col - 1] << " ";


		for (int i = col-1; i > current_layer; i--)
			cout << m[row - 1][i] << " ";


		for (int i = row-1; i > current_layer; i--)
			cout << m[i][current_layer] << " ";

		row--;
		col--;
	}

	

}

int main()
{
	int m[][5] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	print_spiral(m,4,5);
}