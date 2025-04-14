#include<stdio.h>
#include<stdlib.h>
struct student
{
	int id ;
	char name[50];
	int age ;
	float gpa ;
};
struct node
{
	struct student data ;
	struct node* next ;
};
struct node* head = NULL ;
void addstudent (const struct student  const *ptr)
    {
	struct node* current = NULL ;
	struct node *link = (struct node*) malloc(sizeof(struct node));
	if(link == NULL)
		{
			printf("please clear some memory\n");
			return ;
		}
	link -> data = *ptr ;
	link ->next = NULL;

	if(head==NULL)
		{
			head = link;
			return;
		}
	current = head ;
	while(current->next != NULL)
		{
		if(ptr->id != current->data.id)
			current = current->next ;


	    else
	    {
	    	free(link);
		     return ;
	    }


	}
	if(ptr->id == current->data.id)
	{
		return ;
	}
	current ->next = link ;
    }
void displayStudents(void)
{
	struct node * current = head ;
	if(head == NULL)
	{
		printf("empty list\n");
	}
	else
		while(current  != NULL)
		{
			printf("--------------------------------------------------------------------------------\n");
			printf("student name is %s\n",current->data.name);
			printf("student id = %d\n ",current->data.id);
			printf("student age is %d\n",current->data.age);
			printf("student gpa is %f\n",current->data.gpa);
			current = current ->next ;
		}
}
    void searchStudentByID(int id)
{
	struct node* current = head ;
	while(current  != NULL)
	{
		if(id == current->data.id)
		{
			printf("--------------------------------------------------------------------------------\n");
			printf("student name is %s\n",current->data.name);
			printf("student id = %d\n ",current->data.id);
						printf("student age is %d\n",current->data.age);
						printf("student gpa is %f\n",current->data.gpa);

						return ;
		}
		current = current ->next ;
	}
	printf("user not found\n");
}
    void updateStudent(int id)
    {
    	struct node* current = head ;
    		while(current  != NULL)
    		{
    			if(id == current->data.id)
    			{
    				printf("--------------------------------------------------------------------------------\n");
    				printf("please update name\n");
    				scanf("%s",&current->data.name);
    				printf("please update the age \n");
    				scanf("%d",&current->data.age);
    				printf("please update gpa \n");
    				scanf("%f",&current->data.gpa);
    				return ;
    			}
    			current = current ->next ;
    		}
    		printf("user not found\n");
    }
    float calculateAverageGPA(void)
    {
    	float sum = 0 ;
    	int numberOFstudents = 0 ;
    	float result ;
    	struct node* current = head ;
    	if(head == NULL)
    		{
    			printf("avrage gpa is 0.0\n");
    		}
    	while(current  != NULL)
    	{
    		sum = sum + current->data.gpa ;
    		numberOFstudents ++ ;
    		current = current ->next ;
    	}
    	result = sum / numberOFstudents ;
    	return result ;
    }
    void searchHighestGPA(void)
    {
    	struct node* current = head ;
    	struct node* max = head ;
    	if(head == NULL)
    		{
    			printf("empty list\n");
    		}
    		else
    			while(current  != NULL)
    			{
    				if(current->data.gpa > max->data.gpa)
    				{
    					max = current ;
    				}
    				current = current ->next ;
    			}
    	printf("student name is %s\n",max->data.name);
    	printf("student age is %d\n",max->data.age);
    	printf("student gpa is %f\n",max->data.gpa);
    	printf("student id is %d\n",max->data.id);
    }
    void deleteStudent(int id)
    {

    	struct node* previous = head ;
		struct node* deleate = head ;
    	struct node* current = head ;
    	if(head==NULL)
    	{
    		printf("Linked List is empty\n");
    		return;
    	}
    		if(head->data.id == id)
    		{
    			deleate = head ;
    			head = head ->next ;
    			free(deleate);
    			return ;
    		}
    		current = head ->next ;
    		previous = head;
    		while(current != NULL)
    		{
    			if(current->data.id == id)
    			{
    				deleate = current ;
    				previous->next = current->next ;
    				free(deleate);
    				return ;
    			}
    			previous = current ;
    			current = current ->next ;
    		}
    		if(deleate == NULL)
    		{
    			printf("%d not found in the List.\n",id);
    		}

    }
int main  (void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int id ;
	struct student s ;
	int choice = 0;

	while(choice != 8)
	{
		printf("press\n 1.  add student\n");
				printf(" 2.  display students\n");
				printf(" 3.  search student by id \n");
				printf(" 4.  update student information\n");
				printf(" 5.  delete student\n");
				printf(" 6.  calculate average gpa\n");
				printf(" 7.  search for student with highest gpa\n");
				printf(" 8.  exit\n");
				printf("--------------------------------------------------------------------------------\n");
		printf("please enter a number \n");
			scanf("%d",&choice);
			switch (choice)
			{
			case 1 :     	printf("--------------------------------------------------------------------------------\n");
				          printf("name :  ");
			            scanf("%s",s.name);
			              printf("age :  ");
		            	scanf("%d",&s.age);
		            	  printf("gpa :  ");
		            	scanf("%f",&s.gpa);
		            	  printf("id :  ");
		            	scanf("%d",&s.id);

		            	addstudent(&s) ;
		            	break ;

			case 2 :  displayStudents () ; break ;

			case 3 :  printf("please enter id to search for   \n");
			              scanf("%d",&id);
			              searchStudentByID(id);
			              break ;

			case 4  :   printf("please enter id to search for   \n");
                          scanf("%d",&id);
				          updateStudent(id);
			              break ;

			case 5  :     printf("please enter id to search for   \n");
                           scanf("%d",&id);
				           deleteStudent(id);
				           break ;

			case 6	 :      printf("%f",calculateAverageGPA());
			               break ;

			case 7  :         searchHighestGPA();
					       break ;

			default :    printf("invalid input\n");


			}

	}
	printf("terminated\n");
	return 0 ;
}
