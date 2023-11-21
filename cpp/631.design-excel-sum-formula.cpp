/*

Description
Your task is to design the basic function of Excel and implement the function of sum formula. Specifically, you need to implement the following functions:

Excel(int H, char W): This is the constructor. The inputs represents the height and width of the Excel form. H is a positive integer, range from 1 to 26. It represents the height. W is a character range from ‘A’ to ‘Z’. It represents that the width is the number of characters from ‘A’ to W. The Excel form content is represented by a height * width 2D integer array C, it should be initialized to zero. You should assume that the first row of C starts from 1, and the first column of C starts from ‘A’.

void Set(int row, char column, int val): Change the value at C(row, column) to be val.

int Get(int row, char column): Return the value at C(row, column).

int Sum(int row, char column, List of Strings : numbers): This function calculate and set the value at C(row, column), where the value should be the sum of cells represented by numbers. This function return the sum result at C(row, column). This sum formula should exist until this cell is overlapped by another value or another sum formula.

numbers is a list of strings that each string represent a cell or a range of cells. If the string represent a single cell, then it has the following format: ColRow. For example, “F7” represents the cell at (7, F).

If the string represent a range of cells, then it has the following format: ColRow1:ColRow2. The range will always be a rectangle, and ColRow1 represent the position of the top-left cell, and ColRow2 represents the position of the bottom-right cell.

Example 1:

Excel(3,"C"); 
// construct a 3*3 2D array with all zero.
//   A B C
// 1 0 0 0
// 2 0 0 0
// 3 0 0 0

Set(1, "A", 2);
// set C(1,"A") to be 2.
//   A B C
// 1 2 0 0
// 2 0 0 0
// 3 0 0 0

Sum(3, "C", ["A1", "A1:B2"]);
// set C(3,"C") to be the sum of value at C(1,"A") and the values sum of the rectangle range whose top-left cell is C(1,"A") and bottom-right cell is C(2,"B"). Return 4. 
//   A B C
// 1 2 0 0
// 2 0 0 0
// 3 0 0 4

Set(2, "B", 2);
// set C(2,"B") to be 2. Note C(3, "C") should also be changed.
//   A B C
// 1 2 0 0
// 2 0 2 0
// 3 0 0 6
Note:

You could assume that there won’t be any circular sum reference. For example, A1 = sum(B1) and B1 = sum(A1).
The test cases are using double-quotes to represent a character.
Please remember to RESET your class variables declared in class Excel, as static/class variables are persisted across multiple test cases. Please see here for more details.
Solution
In class Excel, maintain the number of rows and the number of columns, the cells, and two maps that stores each cell and the sum cells relevant to the cell and stores each sum cell and the cells relevant to the sum cell, respectively.

For the constructor, initialize the number of rows to H + 1 and the number of columns to W - 'A' + 1, initialize the cells with the rows and the columns, and initialize the two maps.

For method set, set the given cell’s value to v, remove the relations in the two maps between the current cell and other cells where the current cell is a sum cell (which means the current cell’s value equals the sum of one or several other cells), and update the cells’ values that are directly or indirectly affected by the current cell.

For method get, simply get the value of the given cell and return.

For method sum, first obtain the given cell’s value and call method set to remove the relations of the previous sum formula (if it exists), then update the two maps and calculate the sum of the current cell, and finally update the cells’ values that are directly or indirectly affected by the current cell, which is the same as the last step in method set.

*/