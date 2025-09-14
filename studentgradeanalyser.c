#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX_STUDENTS 50
#define MAX_SUBJECTS 5
typedef struct{
char name[50];
int marks[MAX_SUBJECTS];
float average;
char grade;
}Student;
char calculateGrade(float avg){
if(avg>=90)return 'A';
else if(avg>=75)return 'B';
else if(avg>=60)return 'C';
else if(avg>=40)return 'D';
else return 'F'; }
int main(){
int n,i,j,total;
Student students[MAX_STUDENTS];
FILE *fp;
clrscr();
printf("Enter num of students:");
scanf("%d",&n);
fp=fopen("grades.txt","w");
if(!fp){
printf("Error opening file!\n");
exit(0);
}
for(i=0;i<n;i++){
printf("Enter name of student %d:",i+1);
scanf("%s",students[i].name);
 total=0;
for(j=0;j<MAX_SUBJECTS;j++){
printf("Enter marks in subject %d:",j+1);
scanf("%d",&students[i].marks[j]);
total+=students[i].marks[j];
}
students[i].average=total/(float)MAX_SUBJECTS;
students[i].grade=calculateGrade(students[i].average);
fprintf(fp,"Name:%s\nAverage:%.2f\nGrade:%c\n\n",students[i].name,students[i].average,students[i].grade);
}
fclose(fp);
printf("\n Grades saved to grades.txt\n");
getch();
return 0; }
