#include <stdio.h>
int main() {
	int score = 0, total= 0;
	while(score < 10) {
		total += score;
		printf("\nScore =%d, Total =%d", score++,total);
	}
	return 0;
}
/*
The output of the following program is
Score =0, Total =0
Score =1, Total =1
Score =2, Total =3
Score =3, Total =6
Score =4, Total =10
Score =5, Total =15
Score =6, Total =21
Score =7, Total =28
Score =8, Total =36
Score =9, Total =45

-It starts at "Score =0, Total =0" since both score variable and total variable was declared as 0 in the code.
The condition of the loop is score < 10 ,hence the program will keep looping until the score reaches the value of 9 (before the value limit
which is 10 since it was coded score<10). 
-The first output of the loop is "Score =0, Total =0" since it was declared that way in the code
(int score = 0, total = 0;).
Since there is a code (score++) in the code (printf("\nScore =%d, Total =%d", score++,total);)
the original value of score which is 0 is increased by 1 on each loop hence the next value of score variable
would be 1 (Score =1)
-The value of total become 1 because of the code (total+=score)
which add the previous value of total which is 0 and the value of score which is 1, hence the new value of total
is 1 (Total =1) causing the second output of the loop to be (Score =1, Total =1).
-It keeps repeating this process as the value of score keeps increasing by 1 until the value of score reaches 9 (< 10). 
-To demonstrate, The previous output of the loop "Score = 1, Total = 1"
will become "Score =2, Total =3" (Total = 1 + 2) in the next output.
-The next output after "Score =2, Total =3" will be "Score =3, Total =6" (Total = 3 + 3) and so on until the value of 
score variable reaches 9 (< 10), hence the final output of the loop would be "Score =9, Total =45" (Total = 36 + 9).
*/
