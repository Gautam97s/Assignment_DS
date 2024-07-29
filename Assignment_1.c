#include<stdio.h>
#include<string.h>

struct student{
	int rollNo;
	char name[50];
	float marks;
};


void acceptData(struct student s1[20], int n){
	for(int i=0; i<n; i++){
		printf("Enter the student details %d\n", i+1);
		printf("\n enter roll no: ");
		scanf("%d", &s1[i].rollNo);
		printf("\n enter name: ");
		scanf("%s", s1[i].name);
		printf("\n enter marks: ");
		scanf("%f", &s1[i].marks);
	}
}

void displayData(struct student s1[20], int n){
	printf("rollNo\t name\t marks\n");
	for(int i=0; i<n; i++){
		printf("%d\t %s\t %f\n", s1[i].rollNo, s1[i].name, s1[i].marks);
	}
}

void bubbleSort(struct student s1[20], int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1-i; j++){
			if(s1[j].rollNo > s1[j+1].rollNo){
				struct student temp = s1[j];
				s1[j] = s1[j+1];
				s1[j+1] = temp;
			}
		}
	}
}

void insertionSort(struct student s1[20], int n){
	for(int i=0; i<=n-1; i++){
		int j = i;
		while(j>0 && s1[j-1].rollNo >  s1[j].rollNo){
			struct student temp = s1[j-1];
			s1[j-1] = s1[j];
			s1[j] = temp;

			j--;
		}
	}
}

void selectionSort(struct student s1[20], int n){
	for(int i=0; i<=n-2; i++){
		int min=i;
		for(int j=i; j<=n-1; j++){
			if(s1[j].rollNo < s1[i].rollNo){
				min = j;
				struct student temp = s1[i];
				s1[i] = s1[min];
				s1[min] = temp;
			}
		}
	}
}

void shellSort(struct student s1[20], int n){
	for(int gap = n/2; gap>=1; gap=gap/2){
		for(int j=gap; j<n; j++){
			for(int i=j-gap; i>=0; i=i-gap){
				if(s1[i+gap].rollNo > s1[i].rollNo){
					break;
				}else{
					struct student temp = s1[i + gap];
					s1[i + gap] = s1[i];
					s1[i] = temp;
				}
            }
		}
	}
}


int main(){
	struct student s1[20];
		int n, choice;

		printf("Enter the number of student:");
		scanf("%d", &n);

		acceptData(s1, n);
		printf("The details of students are\n");
		displayData(s1,n);

		printf("Enter the choice\n");
		printf("1-bubbleSort\n");
		printf("2-insertionSort\n");
		printf("3-selectionSort\n");
		printf("4-shellSort");
		scanf("%d", &choice);

		switch(choice){
		case 1:bubbleSort(s1,n);
		break;
		case 2:insertionSort(s1,n);
		break;
		case 3:selectionSort(s1,n);
		break;
		case 4:shellSort(s1,n);
		break;
		default:
			printf("wrong choice");
		}

		displayData(s1,n);
		return 0;
}