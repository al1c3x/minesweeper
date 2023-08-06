#include <stdio.h>
#include "interface.h"
#include <string.h>
/*Programmed by: SANTOS,JOSEPH CHRISTOPHER C. S18
Description: This program ask a users input in order to 
create a minesweeper level and play the created minesweeper level.
It can also save the created minesweeper level or load it.
Last modified: September 30
*/
struct boardinfo{
int r;
int c;
int numberofmines;
char board[15][15];
struct boardinfo *next;
};
typedef struct boardinfo node;
/* This function shows at the beginning of the program
@param: none
@return: void
*/
void loadingscreen()
{
iSetColor(I_COLOR_YELLOW);
printf("WELCOME TO MINESWEEPER");
printf("\n\n\n\n");
iSetColor(I_COLOR_WHITE);
printf("press enter");
getchar();
}
/* This function follows the loading screen and is being looped until
user inputs 5 to exit the program
@param: (int*) this gets the users input
@return: void
*/
void mainmenu(int *select)
{
printf("MINESWEEPER\n");
printf("[1] - PLAY GAME\n");
printf("[2] - CREATE LEVEL SET\n");
printf("[3] - SAVE LEVEL SET\n");
printf("[4] - LOAD LEVEL SET\n");
printf("[5] - EXIT\n");
scanf("%d", select);
}
/* This function is to initialize the node
@param: (node **) initializing the node
return: void
*/
void intializenode(node **pHead)
{
*pHead = NULL;
}
/* This function counts how many elements 
the linked list contains
@param: (node*) the node to be counted
@return: int the number of elements in a node
*/
int getcount(node *pHead)
{
int count = 0;
node *current = pHead;
while(current != NULL)
{
count++;
current = current->next;
}
return count;
}
/* This function initialize the state of the board
@param: char * board is to be initialized
@return:void
*/
void initializeboard(char board[15][15])
{
int i;
int j;
for(i = 0; i < 15; i++)
{
for(j = 0; j < 15; j++)
{
board[i][j] = '-';
}
}
}
/* This function display the board depending on the length 
of the rows and columns.
rows and columns have a minimum value of 5 and maximum value of 15
@param: (char *), (int) board is to be display while rows and columns are
the one to set the board
@return: void
*/
void printboard(char board[15][15], int rows, int columns)
{
int i;
int j;
for(i = 0; i < rows; i++)
{
for(j = 0; j < columns; j++)
{
printf("%c",board[i][j]);
}
printf("\n");
}
}
/* This function display the options when editing 
the board 
@param:none
@return: void
*/
void mineoption()
{
printf("Select action to do:\n");
printf("1 - Add mine\n");
printf("2 - Remove mine\n");
printf("3 - Return to main menu\n");
}
/* This function adds a node at the end of the linked list
however, when the linked list has no element the node
is added as the first node
@param: (node **)(int)(char*) the values of the int and char* will be stored at 
node**
@return:void
*/
void addnode(node **pHead,int rows, int columns,int minecount,char board[15][15])
{
node *pRun = malloc(sizeof(node));
node *pTemp = *pHead;
int i;
int j;
pRun->c = columns;
pRun->r = rows;
pRun->numberofmines = minecount;
for(i = 0; i < 15; i++)
{
for(j = 0; j < 15; j++)
{
pRun->board[i][j] = board[i][j];
}
}
pRun->next = NULL;
if(*pHead == NULL)
{
*pHead =pRun;
return;
}
while(pTemp->next != NULL)
{
pTemp = pTemp->next;
}
pTemp->next = pRun;
}
/* This function display the options 
to add flag or remove flag
@param: none
@return: void
*/
void flag()
{
printf("[1] - ADD FLAG\n");
printf("[2] - REMOVE FLAG\n");
}
/* This function deallocates the memory used
in the program
@param: (node*) deallocating memory
@return: void
*/
void deallocate(node *pHead)
{
node *pRun;
node *pTrail;
pTrail = pHead;
while(pTrail != NULL)
{
pRun = pTrail->next;
free(pTrail);
pTrail = pRun;
}
}
int main()
{
int select;
int x = 1;
int createselect;
char playingboard[15][15];
node *pHead;
node *dump;
int a = 1;
int rows;
int columns;
int options;
int mines;
int minecolumn;
int minerow;
int minecount = 0;
int n;
int r;
int c;
int i;
int j;
int numberofnodes = 0;
int dummyvar;
int movecount = 0;
int g = 3;
int h = 3;
int e = 3;
/* This is where the program begins
by calling the loading screen
*/
loadingscreen();
iClear(0, 0, 30, 6);
/* This loop is an infite loop where it
display the main menu. The loop will only end
when the user input the case of exit
*/
while(e < 4)
{
mainmenu(&select);
iClear(0, 0, 50, 30);
g = 3;
switch(select)
{
/* This case lets you play the level set you created
it will first check whether there is a level set or not
if there is no level set it will ask you to create a level set
if a level set is already created it will then initialize the 
board
to be used and followed by the mechanics of minesweeper
*/
case 1:
{
if(numberofnodes == 0)
{
printf("please create level set\n");
}
else
{
initializeboard(playingboard);
dump = pHead;
while(dump != NULL )
{
printboard(playingboard,dump->r,dump->c);
printf("select action\n");
printf("1 - inspect tile\n");
printf("2 - flag tile\n");
scanf("%d",&createselect);
iClear(0, 0, 50, 30);
if(createselect < 1 || createselect > 2)
{
printf("Invalid option\n");
while(createselect < 1 || createselect > 
2)
{
printf("Select action\n");
scanf("%d",&createselect);
iClear(0, 0, 50, 30);
}
}
switch(createselect)
{
case 1:
{
printf("Input row:\n");
scanf("%d", &rows);
if(rows < 0 || rows > dump->r
- 1)
{
printf("Invalid option \
n");
while(rows < 0 || rows >
dump->r - 1)
{
printf("Input 
row:\n");
scanf("%d", 
&rows);
iClear(0, 0, 50, 
30);
}
}
printf("Input column:\n");
scanf("%d", &columns);
if(columns < 0 || columns > 
dump->c - 1)
{
printf("Invalid option \
n");
while(columns < 0 || 
columns > dump->c - 1)
{
printf("Input 
column:\n");
scanf("%d", 
&columns);
iClear(0, 0, 50, 
30);
}
}
if(dump->board[rows][columns]
== 'X')
{
printf("You lose\
n");
printboard(dump-
>board,dump->r,dump->c);
fflush(stdin);
printf("press 
enter\n");
getchar();
iClear(0, 0, 50, 
30);
dump->next = NULL;
dump = dump->next;
break;
}
else if(dump->board[rows]
[columns] != 'X')
{
if(playingboard[rows]
[columns] != '-')
{
printf("tile is 
already inspected\n");
}
else {
if(dump->board[rows-1]
[columns-1] == 'X')
{
minecount++;
}
if(dump->board[rows-1]
[columns] == 'X')
{
minecount++;
}
if(dump->board[rows-1]
[columns+1] == 'X')
{
minecount++;
}
if(dump->board[rows]
[columns-1] == 'X')
{
minecount++;
}
if(dump->board[rows]
[columns+1] == 'X')
{
minecount++;
}
if(dump->board[rows+1]
[columns-1] == 'X')
{
minecount++;
}
if(dump->board[rows+1]
[columns] == 'X')
{
minecount++;
}
if(dump->board[rows+1]
[columns+1] == 'X')
{
minecount++;
}
playingboard[rows]
[columns] = minecount +'0';
movecount++;
minecount = 0;
}
printf("number of 
moves:%d\n", movecount);
}
if(movecount == (dump-
>r*dump->c) - dump->numberofmines)
{
movecount = 0;
printf("Level clear\n");
printboard(dump-
>board,dump->r,dump->c);
fflush(stdin);
printf("press any key to
continue\n");
getchar();
iClear(0, 0, 50, 30);
initializeboard(playingboard);
dump = dump->next;
break;
}
break;
}
case 2:
{
printf("Input row 
number\n");
scanf("%d", &rows);
if(rows < 0 || rows > 
dump->r - 1 )
{
printf("Invalid 
row\n");
while(rows < 0 || 
rows > dump->r - 1)
{
printf("Input row:\n");
scanf("%d", 
&rows);
iClear(0, 0,
50, 30);
}
}
printf("Input column 
number\n");
scanf("%d", &columns);
if(columns < 0 || 
columns > dump->c - 1 )
{
printf("Invalid 
columns\n");
while(columns < 0 
|| columns > dump->c - 1)
{
printf("Input column:\n");
scanf("%d", 
&columns);
iClear(0, 0,
50, 30);
}
}
flag();
scanf("%d",&options);
if(options < 1 || 
options > 2)
{
printf("Invalid 
option\n");
while(options < 1 
|| options > 2 )
{
scanf("%d", 
options);
}
}
switch(options)
{
case 1:
{
if(playingboard[rows][columns] == '-')
{
playingboard[rows][columns] = 'F';
}
else 
if(playingboard[rows][columns] == 'F')
{
printf("mine is already flagged\n");
}
else
{
printf("cannot be flagged\n");
}
break;
}
case 2:
{
if(playingboard[rows][columns] == '-')
{
printf("Tile is not flagged\n");
}
else 
if(playingboard[rows][columns]== 'F')
{
playingboard[rows][columns] = '-';
}
else
{
printf("tile is revealed\n");
}
break;
}
default:
{
printf("Invalid option\n");
break;
}
}
break;
}
default:
{
printf("Invalid option\n");
break;
}
}
}
printf("THANK YOU FOR PLAYING \n");
}
break;
}
/* This function creates a level set that the player can play or 
save
This case ask the rows and columns for the board
then edit the board to add or remove a mine
if the board doesn't contain a mine the level wont be added
to the list
*/
case 2:
{
intializenode(&pHead);
do
{
printf("%d\n", getcount(pHead));
printf("[1] - CREATE LEVEL\n");
printf("[2] - RETURN TO MAIN MENU\n");
scanf("%d", &createselect);
iClear(0, 0, 50, 30);
switch(createselect)
{
/* this case ask the user to input rows 
and columns for the board
the minimum size is 5 and the maximum is 
15
when the user input an invalid size then 
an error message Invalid will be
displayed and ask the user repeatedly 
until the user gives a valid size 
In this case also creates and edit a 
board
 */
case 1:
{
printf("Enter number of 
rows(min:5,max:15):\n");
scanf("%d", &rows);
iClear(0, 0, 50, 30);
if(rows < 5 || rows > 
15)
{
printf("Invalid\
n");
while(rows < 5 || 
rows > 15)
{
printf("Enter number of rows(min:5,max:15):\n");
scanf("%d", 
&rows);
iClear(0, 0,
50,30);
}
}
printf("Enter number of 
columns(min:5,max:15):\n");
scanf("%d", &columns);
iClear(0, 0, 50, 30);
if(columns < 5 || 
columns > 15)
{
printf("Invalid\
n");
while(columns < 5 
|| columns > 15)
{
printf("Enter number of columns(min:5,max:15):\n");
scanf("%d", 
&columns);
iClear(0, 0,
50, 30);
}
}
initializeboard(playingboard);
do
{
printboard(playingboard,
rows, columns);
mineoption();
scanf("%d",&mines);
if(mines < 1 || mines > 
3 )
{
while(mines 
< 1 || mines > 3)
{
scanf("%d",&mines);
iClear(0, 0, 50, 30);
}
}
iClear(0, 0, 50, 30);
switch(mines)
{
/* In this 
case it adds a mine on the board
depending on
the users input for the minerow and mine column
An error 
message will be displayed when the user input the same
minerow and 
column
*/
case 1:
{
printf("Enter column to add mine: ");
scanf("%d",&minecolumn);
if(minecolumn < 0 || minecolumn > columns - 1)
{
while(minecolumn < 0 || minecolumn > columns - 1)
{ 
printf("Enter column to add mine: ");
scanf("%d",&minecolumn);
iClear(0, 0, 50, 30);
}
}
printf("Enter row to add mine: ");
scanf("%d",&minerow );
if(minerow < 0 || minerow > rows - 1)
{
while(minerow < 0 || minerow > rows - 1)
{
printf("Enter row to add mine: ");
scanf("%d",&minerow );
iClear(0, 0, 50, 30);
}
}
if(playingboard[minerow][minecolumn]=='X')
{
printf("Tile contains mine\n");
}
else
{
playingboard[minerow][minecolumn] = 'X';
minecount++;
}
break;
}
/* This 
function deletes a mine on the board depending on
the users 
input for minecolumn and row
if the user 
inputs a minecolumn and minerow with no mine
an error 
message will be displayed
if the user 
inputs a minecolumn and minerow while the board
doesnt 
contain a mine then an error message will be displayed
*/
case 2:
{
if(minecount == 0)
{
printf("please add mine to the board\n");
}
else
{
printf("Enter column to delete mine: ");
scanf("%d",&minecolumn);
if(minecolumn < 0 || minecolumn > columns - 1)
{
while(minecolumn < 0 ||minecolumn > columns - 1)
{ 
printf("Enter column to delete mine: ");
scanf("%d",&minecolumn);
iClear(0, 0, 50, 30);
}
}
printf("Enter row to delete mine: ");
scanf("%d",&minerow );
if(minerow < 0 || minerow > rows - 1)
{
while(minerow < 0 || minerow > rows - 1)
{
printf("Enter row to delete mine: ");
scanf("%d",minerow );
iClear(0, 0, 50, 30);
}
}
if( playingboard[minerow][minecolumn] != 'X')
{
printf("Tile does not contain mine\n");
}
else
{
playingboard[minerow][minecolumn] = '-';
minecount--;
}
}
break;
}
/* This case
ends the while loop and return to the level create set
*/
case 3:
{
if(minecount == 0)
{
printf("please add mine\n");
}
else
{
h++;
}
break;
}
/* if the 
user input is not in the range then an invalid message will appear
*/
default:
{
printf("Invalid option\n");
break;
}
}
}
while(h < 4);
if(minecount > 0)
{
h = 3;
printf("Level create 
success\n");
addnode(&pHead, rows, 
columns, minecount, playingboard);
minecount = 0;
}
else
{
printf("Invalid board\
n");
}
break;
}
/* This case returns the user to the main
menu if 
there is no node created an error message
will be displayed.
If there is a node created the a success 
message will be displayed
*/
case 2:
{
if(getcount(pHead) == 0)
{
printf("please create 
level\n");
}
else
{
g++;
}
break;
}
/* This display an invalid option when 
the user an input not in the range
*/
default:
{
printf("Invalid option \n");
break;
}
}
}
while(g < 4);
printf("Level set successfully created\n");
numberofnodes = getcount(pHead);
break;
}
/* This case save the data that was created in case 2
 The first data that will be written is the number of elements 
 followed by the row and columns and the board 
*/
case 3:
{
FILE *filepointer;
filepointer = fopen("file1.txt", "w");
if(filepointer == NULL)
{
printf("Error\n");
}
fprintf(filepointer,"%d\n", getcount(pHead));
dump = pHead;
while(dump != NULL)
{
fprintf(filepointer,"%d\n",dump->r);
fprintf(filepointer,"%d\n",dump->c);
for(i = 0; i < dump->r; i++)
{
for(j = 0; j < dump->c; j++)
{
fprintf(filepointer, "%c", dump->board[i][j]);
}
fprintf(filepointer,"\n");
}
dump = dump->next;
}
fclose(filepointer);
break;
}
/* This case will read a file and transfer the data into 
the node. The first fcanf will be the number of nodes 
should be created followed by the information of the nodes
*/
case 4:
{
FILE *filepointer;
filepointer = fopen("file1.txt", "r");
if(filepointer == NULL)
{
printf("Error\n");
}
fscanf(filepointer, "%d", &n);
intializenode(&pHead);
numberofnodes = 0;
while(numberofnodes <= n)
{
fscanf(filepointer, "%d", &r);
fscanf(filepointer, "%d", &c);
for(i = 0; i < r; i++)
{
fscanf(filepointer, "%c", &dummyvar);
for( j = 0; j < c; j++)
{
fscanf(filepointer, "%c", 
&playingboard[i][j]);
}
}
for(i = 0; i < r; i++)
{
for(j = 0; j < c; j++)
{
if(playingboard[i][j] == 'X')
{
minecount++;
}
}
}
addnode(&pHead, r, c, minecount, 
playingboard);
minecount = 0;
numberofnodes++;
}
numberofnodes--;
break;
}
/* if this case is selected the program will end
*/
case 5:
{
e++;
break;
}
/* if the given input of the user is not in the range this will 
appear
*/
default:
{
printf("Invalid option\n");
break;
}
}
}
/* checks whether the program allocated 
memory and free it
*/
if(numberofnodes < 0)
{
deallocate(pHead);
}
/* End of program
*/
return 0;
}
