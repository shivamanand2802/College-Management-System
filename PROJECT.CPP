#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>

	/* Structure for student's details */

struct stu_detail
{
	int stu_cls_roll,sem;
	char stu_fir_nm[15],stu_lst_nm[15],stu_fat_fir_nm[20],stu_fat_lst_nm[20],stu_mot_fir_nm[20],stu_mot_lst_nm[20],dob[11],uidai[15],course_session[10],uniq_roll[15],address[100],mob_no[17];
};

	/* Structure for Faculty's details */

struct fact_detail
{
	char fact_fir_nm[15],fact_lst_nm[15],mob_no[17],sub[20],uidai[15],dob[11],address[100],exp[10];
};

	/* Structure for College's details */

struct coll_detail
{
	char hod_fir_nm[15],hod_lst_nm[15],mob_no[17],dob[11],dep[25],address[100],uidai[15];
};
struct all_detail
{
	int pass_yr;
	char all_fir_nm[15],all_lst_nm[15],all_fat_fir_nm[20],all_fat_lst_nm[20],uidai[15],course_session[10],address[100],mob_no[17],cur_occ[25],cur_city[15],rev[500];
};

	/* Function declaration of respective user defined functions */

void Student();
	void Intro();
	void Add_stu();
	void View_stu_list();
	void Search_stu();
void Faculty();
	void Add_fact();
	void View_fact_list();
	void Search_fact();
void College();
	void Coll_rev();
	void Add_hod();
	void View_hod_list();
	void Search_hod();
void Allumni();
	void Add_All();
	void View_all_list();
	void Search_all();

	/* main function of program */

void main()
{
	char choice;
	Intro();
	gotoxy(33,6);
	printf("Department of BCA");
	gotoxy(33,7);
	printf("*****************\n\n");
	printf("Press 1 for STUDENT\'S PORTAL\n\nPress 2 for FACULTY\'S PORTAL\n\nPress 3 for COLLEGE\'S PORTAL\n\nPress 4 for ALLUMNI\'S PORTAL\n\nPress 5 for EXIT");
	printf("\n\n\nEnter your choice :-> ");
	choice=getche();
	switch(choice)
	{
		case '1':
			Student();
		case '2':
			Faculty();
		case '3':
			College();
		case '4':
			Allumni();
		case '5':
			exit(0);
		default:
			printf("Ahh! You entered wrong input. We bring back you to previous screen. Press any key to continue.");
			getche();
			main();
	}
}

	/* Function defination of student's section */

void Student()
{
	char choice;
	Intro();
	printf("BCA Department > Student\'s portal >\n");
	printf("\nPress 1 for ADD NEW STUENT\'S DETAILS\n\nPress 2 for VIEW LIST OF STUDENTS\n\nPress 3 for SEARCH COMPLETE DETAILS\n\nPress 4 for BACK\n\nPress 5 for EXIT");
	printf("\n\nEnter your choice :-> ");
	choice=getche();
	switch(choice)
	{
		case '1':
			Add_stu();
			Student();
		case '2':
			View_stu_list();
			Student();
		case '3':
			Search_stu();
			Student();
		case '4':
			main();
		case '5':
			exit(0);
		default:
			printf("\nAhh! You entered wrong input. We bring back you to previous screen. Press any key to continue.");
			getch();
			Student();
	}
}

	/* Introductory or Headline function defination */

void Intro()
{
	clrscr();
	gotoxy(30,1);
	printf("M.L.T. COLLEGE, SAHARSA");
	gotoxy(23,2);
	printf("(old name saharsa college, saharsa)");
	gotoxy(15,3);
	printf("(a constituent unit of B.N. Mandal University, Madhepura)");
	gotoxy(5,4);
	printf("Contact number :-> +91-6478-223436\t\tmail :-> info@mltcollege.org\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

	/* Function defination to add new student */

void Add_stu()
{
	char session[10],choice;
	int semester;
	FILE *student;
	struct stu_detail obj;
	Intro();
	printf("BCA Department > Student\'s portal > Add New Student Details >");
	student=fopen("Stu_Database","ab");
	do
	{
		printf("\n\nEnter class roll number of student :-> ");
		scanf("%d",&obj.stu_cls_roll);
		printf("Enter first and last name of student :-> ");
		scanf("%s%s",obj.stu_fir_nm,obj.stu_lst_nm);
		printf("Enter first and last name of student\'s father :-> ");
		scanf("%s%s",obj.stu_fat_fir_nm,obj.stu_fat_lst_nm);
		printf("Enter first and last name of student\'s mother :-> ");
		scanf("%s%s",obj.stu_mot_fir_nm,obj.stu_mot_lst_nm);
		printf("Enter course session :-> ");
		scanf("%s",obj.course_session);
		printf("Enter semester :-> ");
		scanf("%d",&obj.sem);
		printf("Enter unique roll number of student :-> ");
		scanf("%s",obj.uniq_roll);
		printf("Enter recidential address of student (without a single space) :-> ");
		scanf("%s",obj.address);
		printf("Enter aadhaar number of student :-> ");
		scanf("%s",obj.uidai);
		printf("Enter date of birth of student :-> ");
		scanf("%s",obj.dob);
		printf("Enter contact number of student :-> ");
		scanf("%s",obj.mob_no);
		fwrite(&obj,sizeof(struct stu_detail),1,student);
		printf("\nPress 1 to Add details of another student.\nPress 2 to return to previous window.");
		choice=getche();
	}while(choice=='1');
	fclose(student);
	Student();
}

	/* Function defination to display list view of all student */

void View_stu_list()
{
	char session[10];
	int semester,sr;
	FILE *student;
	struct stu_detail obj;
	Intro();
	printf("BCA Department > Student\'s portal > List view >");
	sr=1;
	student=fopen("Stu_Database","rb");
	fread(&obj,sizeof(struct stu_detail),1,student);
	printf("\tRoll\t\t\tName of student\t\t\tUnique roll no.\n");
	while(!feof(student))
	{
		printf("%d.) %d\t\t\t%s %s\t\t\t%s\n",sr,obj.stu_cls_roll,obj.stu_fir_nm,obj.stu_lst_nm,obj.uniq_roll);
		fread(&obj,sizeof(struct stu_detail),1,student);
		if(sr%16==0)
		{
			Intro();
			printf("BCA Department > Student\' portal > List view >\n");
		}
		sr++;
	}
	printf("Press any Key to Continue.");
	getch();
	fclose(student);
	Student();
}

	/* Function to search among list of all students */

void Search_stu()
{
	char session[10];
	//int choice;
	int semester,roll_number;
	FILE *student;
	struct stu_detail obj;
	Intro();
	printf("BCA Department > Student\'s portal > Search complete details >");
	student=fopen("Stu_Database","rb");
	fread(&obj,sizeof(struct stu_detail),1,student);
	printf("Enter class roll number of student :-> ");
	scanf("%d",&roll_number);
	while(!feof(student))
	{
		if(roll_number==obj.stu_cls_roll)
		{
			printf("1.) Class roll number of student :-> %d",obj.stu_cls_roll);
			printf("\n2.) First and last name of student :-> %s %s",obj.stu_fir_nm,obj.stu_lst_nm);
			printf("\n3.) First and last name of student\'s father :-> %s %s",obj.stu_fat_fir_nm,obj.stu_fat_lst_nm);
			printf("\n4.) First and last name of student\'s mother :-> %s %s",obj.stu_mot_fir_nm,obj.stu_mot_lst_nm);
			printf("\n5.) Course session :-> %s",obj.course_session);
			printf("\n6.) Semester :-> %d",obj.sem);
			printf("\n7.) Unique roll number of student :-> %s",obj.uniq_roll);
			printf("\n8.) Recidential address of student (without a single space) :-> %s",obj.address);
			printf("\n9.) Aadhaar number of student :-> %s",obj.uidai);
			printf("\n10.) Date of birth of student :-> %s",obj.dob);
			printf("\n11.) Contact number of student :-> %s",obj.mob_no);
		       /*printf("\n\nDo you want to update anything.");
			printf("\nPress 1 to UPDATE ANYTHING.\nPress 2 to BACK");
			scanf("%d",&choice);
			if(choice!=1)    */
			getch();
			Student();
		       /*else
			{
				printf("\nWhich detail you want to update.");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:
						printf("\n\nEnter class roll number of student :-> ");
						scanf("%d",&obj.stu_cls_roll);
						break;
					case 2:
						printf("Enter first and last name of student :-> ");
						scanf("%s%s",obj.stu_fir_nm,obj.stu_lst_nm);
						break;
					case 3:
						printf("Enter first and last name of student\'s father :-> ");
						scanf("%s%s",obj.stu_fat_fir_nm,obj.stu_fat_lst_nm);
						break;
					case 4:
						printf("Enter first and last name of student\'s mother :-> ");
						scanf("%s%s",obj.stu_mot_fir_nm,obj.stu_mot_lst_nm);
						break;
					case 5:
						printf("Enter course session :-> ");
						scanf("%s",obj.course_session);
						break;
					case 6:
						printf("Enter semester :-> ");
						scanf("%d",&obj.sem);
						break;
					case 7:
						printf("Enter unique roll number of student :-> ");
						scanf("%s",obj.uniq_roll);
						break;
					case 8:
						printf("Enter recidential address of student (without a single space) :-> ");
						scanf("%s",obj.address);
						break;
					case 9:
						printf("Enter aadhaar number of student :-> ");
						scanf("%s",obj.uidai);
						break;
					case 10:
						printf("Enter date of birth of student :-> ");
						scanf("%s",obj.dob);
						break;
					case 11:
						printf("Enter contact number of student :-> ");
						scanf("%s",obj.mob_no);
						break;
					default:
						printf("You entered wrong input. we are taking you back to previous window. press any key to continue.");
						getch();
						Modify_stu();
				}
				fwrite(&obj,sizeof(struct stu_detail),1,student);
				printf("\nDetails updated successfully.");
				printf("\nPress 1 to update another one.\nPress 2 for exit.");
				scanf("%d",&choice);
				if(choice==1)
				Modify_stu();
				else
				Student();
			}  */
		}
		else
			fread(&obj,sizeof(struct stu_detail),1,student);
	}
}

	/* Function defination of Faculty section */

void Faculty()
{
	char choice;
	Intro();
	printf("BCA Department > Faculty\'s portal >\n");
	printf("\nPress 1 for ADD NEW FACULTY\'S DETAILS\n\nPress 2 for VIEW LIST OF FACULTY\'S\n\nPress 3 for SEARCH COMPLETE DETAILS\n\nPress 4 for BACK\n\nPress 5 for EXIT");
	printf("\n\nEnter your choice :-> ");
	choice=getche();
	switch(choice)
	{
		case '1':
			Add_fact();
			Faculty();
		case '2':
			View_fact_list();
			Faculty();
		case '3':
			Search_fact();
			Faculty();
		case '4':
			main();
		case '5':
			exit(0);
		default:
			printf("\nYou entered wrong input. We bring back you to previous screen. Press any key to continue.");
			getche();
			Faculty();
	}
}

	/* Function defination to add new faculty to the list */

void Add_fact()
{
	char choice;
	FILE *faculty;
	struct fact_detail obj;
	Intro();
	printf("BCA Department > Faculty\'s portal > Add New Faculty Details >");
	faculty=fopen("Fac_Database","ab");
	do
	{
		printf("\n\nEnter first and last name of faculty :-> ");
		scanf("%s%s",obj.fact_fir_nm,obj.fact_lst_nm);
		printf("\nEnter date of birth of faculty :-> ");
		scanf("%s",obj.dob);
		printf("Enter faculty\'s subject :-> ");
		scanf("%s",obj.sub);
		printf("Enter teaching experience of the faculty :-> ");
		scanf("%s",obj.exp);
		printf("Enter contact number of faculty :-> ");
		scanf("%s",obj.mob_no);
		printf("Enter aadhar no. of faculty :-> ");
		scanf("%s",obj.uidai);
		printf("Enter residential address of faculty :-> ");
		scanf("%s",obj.address);
		fwrite(&obj,sizeof(struct fact_detail),1,faculty);
		printf("\nPress 1 to Add details of another faculty.\nPress 2 to return to previous window.\n");
		choice=getch();
	}while(choice=='1');
	fclose(faculty);
	Faculty();
}

	/* Function defination to display all faculty details in list view */

void View_fact_list()
{
	int sr=1;
	FILE *faculty;
	struct fact_detail obj;
	Intro();
	printf("BCA Department > Faculty\'s portal > List view >");
	faculty=fopen("Fac_Database","rb");
	fread(&obj,sizeof(struct fact_detail),1,faculty);
	printf("\nS.No.\t\t\tName of faculty\t\t\tSubject\n");
	while(!feof(faculty))
	{
		printf("%d\t\t\t%s %s\t\t\t%s\n",sr,obj.fact_fir_nm,obj.fact_lst_nm,obj.sub);
		fread(&obj,sizeof(struct fact_detail),1,faculty);
		if(sr%16==0)
		{
			Intro();
			printf("BCA Department > Faculty\'s portal > List view >\n");
		}
		sr++;
	}
	printf("Press any Key to Continue.");
	getch();
	fclose(faculty);
	Faculty();
}

	/* Function defination to search faculty details among list of all faculty */

void Search_fact()
{
	char first[15],last[15];
	FILE *faculty;
	struct fact_detail obj;
	Intro();
	printf("BCA Department > Faculty\'s portal > Search complete details >");
	printf("\nEnter first and last name of faculty :-> ");
	scanf("%s%s",first,last);
	faculty=fopen("Fac_Database","rb");
	fread(&obj,sizeof(struct fact_detail),1,faculty);
	while(!feof(faculty))
	{
		if(!(stricmp(first,obj.fact_fir_nm)&&stricmp(last,obj.fact_lst_nm)))
		{
			printf("\n1.) Name of faculty :-> %s %s",obj.fact_fir_nm,obj.fact_lst_nm);
			printf("\n2.) Date of birth of faculty :-> %s",obj.dob);
			printf("\n3.) Subject of faculty :-> %s",obj.sub);
			printf("\n4.) Recidential address of faculty (without a single space) :-> %s",obj.address);
			printf("\n5.) Aadhaar number of faculty :-> %s",obj.uidai);
			printf("\n6.) Teaching experience of faculty :-> %s",obj.exp);
			printf("\n7.) Contact number of faculty :-> %s",obj.mob_no);
			getch();
		}
			fread(&obj,sizeof(struct fact_detail),1,faculty);
	}
	fclose(faculty);
	Faculty();
}

	/* Function defination of college's section */


void College()
{
	char choice;
	Intro();
	printf("BCA Department > College\'s portal >\n");
	printf("\nPress 1 for ABOUT COLLEGE\n\nPress 2 for ADD HOD\'S DETAILS\n\nPress 3 for VIEW HOD\'S LIST\n\nPress 4 for SEARCH COMPLETE DETAILS\n\nPress 5 for BACK\n\nPress 6 for EXIT");
	printf("\n\nEnter your choice :-> ");
	choice=getche();
	switch(choice)
	{
		case '1':
			Coll_rev();
			College();
		case '2':
			Add_hod();
			College();
		case '3':
			View_hod_list();
			College();
		case '4':
			Search_hod();
			College();
		case '5':
			main();
		case '6':
			exit(0);
		default:
			printf("\nAhh! You entered wrong input. We bring back you to previous screen. Press any key to continue.");
			getch();
			College();
	}
}
void Coll_rev()
{
clrscr();
gotoxy(30,1);
printf("#WELCOME TO MLT COLLEGE#");
printf("\nAbout:->\n\nMLT College is a constituent of BNMU Madhepura.The old name of MLT COllege is Saharsa College.\nRai Saheb Manohar Lal Tekriwal made a Remarkable contribution.On his memory college was named MLT Colege(Manohar Lal Tekriwal)from Saharsa College by decision of BNMU and State Government.\nMLT College premier institution for Boys and Girls and well known in the koshi region for its value based education quality teaching and discipline.\n");
printf("College is situated over 11.80 acres of land at the center of saharsa district.there are big playground and a hostel in this college.\n");
printf("Instead of this is study center of IGNOU and NOU.");
printf("\n\nDepartment of our college:->\n");
printf("\nThese are department of our college:->");
printf("\nDepartment related to science:->");
printf("\n\t1.Department of Zoology\n\t2.Department of Botony\n\t3.Department of Physics\n\t4.Department of Mathematics\n\t5.Department of Chemistry");
getch();
printf("\nDepartment related to Humanities:->");
printf("\n\t1.Department of Economics\n\t2.Department of English\n\t3.Department of Hindi\n\t4.Department of History\n\t5.Department of maithili\n\t6.Department of Philosophy\n\t7.Department of Political science\n\t8.Department of Sanskrit.");
printf("\nDepartment related to Technical branch:->");
printf("\n\t1.Department of BCA\n\t2.Department of Biotechnology\n\t3.Department of Education (B.Ed)");
printf("\nIn our college Post Graduation(PG) course in History,Economics,Political Science,English,Hindi,Maithili,and all subjects related to Science and Math are also available.");
getch();
College();
}
void Add_hod()
{
	char choice;
	FILE *college;
	struct coll_detail obj;
	Intro();
	printf("BCA Department > Faculty\'s portal > Add New Faculty Details >");
	college=fopen("Col_Database","ab");
	do
	{
		printf("\n\nEnter first and last name of HOD :-> ");
		scanf("%s%s",obj.hod_fir_nm,obj.hod_lst_nm);
		printf("\nEnter date of birth of HOD :-> ");
		scanf("%s",obj.dob);
		printf("Enter HOD\'s department :-> ");
		scanf("%s",obj.dep);
		printf("Enter contact number of HOD :-> ");
		scanf("%s",obj.mob_no);
		printf("Enter aadhar no. of HOD :-> ");
		scanf("%s",obj.uidai);
		printf("Enter residential address of HOD :-> ");
		scanf("%s",obj.address);
		fwrite(&obj,sizeof(struct coll_detail),1,college);
		printf("\nPress 1 to Add details of another HOD.\nPress 2 to return to previous window.\n");
		choice=getch();
	}while(choice=='1');
	fclose(college);
	College();
}
void View_hod_list()
{
	int sr=1;
	FILE *college;
	struct coll_detail obj;
	Intro();
	printf("BCA Department > College\'s portal > List view >");
	college=fopen("Col_Database","rb");
	fread(&obj,sizeof(struct coll_detail),1,college);
	printf("\nS.No.\t\t\tName of HOD\t\t\tDepartment\n");
	while(!feof(college))
	{
		printf("%d\t\t\t%s %s\t\t\t%s\n",sr,obj.hod_fir_nm,obj.hod_lst_nm,obj.dep);
		fread(&obj,sizeof(struct coll_detail),1,college);
		if(sr%16==0)
		{
			Intro();
			printf("BCA Department > College\'s portal > List view >\n");
		}
		sr++;
	}
	printf("Press any Key to Continue.");
	getch();
	fclose(college);
	College();
}
void Search_hod()
{
	char first[15],last[15];
	FILE *college;
	struct coll_detail obj;
	Intro();
	printf("BCA Department > College\'s portal > Search complete details >");
	printf("\nEnter first and last name of HOD :-> ");
	scanf("%s%s",first,last);
	college=fopen("Col_Database","rb");
	fread(&obj,sizeof(struct coll_detail),1,college);
	while(!feof(college))
	{
		if(!(stricmp(first,obj.hod_fir_nm)&&stricmp(last,obj.hod_lst_nm)))
		{
			printf("\n1.) Name of Hod :-> %s %s",obj.hod_fir_nm,obj.hod_lst_nm);
			printf("\n2.) Date of birth of HOD :-> %s",obj.dob);
			printf("\n3.) Department of HOD :-> %s",obj.dep);
			printf("\n4.) Recidential address of HOD (without a single space) :-> %s",obj.address);
			printf("\n5.) Aadhaar number of HOD :-> %s",obj.uidai);
			printf("\n6.) Contact number of HOD :-> %s",obj.mob_no);
			getch();
		}
			fread(&obj,sizeof(struct coll_detail),1,college);
	}
	fclose(college);
	College();
}
void Allumni()
{
	char choice;
	Intro();
	printf("BCA Department > allumni\'s portal >\n");
	printf("\nPress 1 for ADD ALLUMNI DETAILS\n\nPress 2 for VIEW ALLUMNI\'S LIST\n\nPress 3 for SEARCH COMPLETE DETAILS\n\nPress 4 for BACK\n\nPress 5 for EXIT");
	printf("\n\nEnter your choice :-> ");
	choice=getche();
	switch(choice)
	{
		case '1':
			Add_All();
			Allumni();
		case '2':
			View_all_list();
			Allumni();
		case '3':
			Search_all();
			Allumni();
		case '4':
			main();
		case '5':
			exit(0);
		default:
			printf("\nAhh! You entered wrong input. We bring back you to previous screen. Press any key to continue.");
			getch();
			Allumni();
	}
}
void Add_All()
{
	int a;
	char choice;
	FILE *allumni;
	struct all_detail obj;
	Intro();
	printf("BCA Department > allumni\'s portal > Add New Allumni Details >");
	do
	{
		allumni=fopen("Allum_Database","ab");
		printf("\nEnter first and last name of allumni :-> ");
		scanf("%s %s",obj.all_fir_nm,obj.all_lst_nm);
		printf("Enter first and last name of allumni\'s father :-> ");
		scanf("%s %s",obj.all_fat_fir_nm,obj.all_fat_lst_nm);
		printf("Enter course session :-> ");
		scanf("%s",obj.course_session);
		printf("Enter passing year of allumni :-> ");
		scanf("%d",&obj.pass_yr);
		printf("Enter current occupation of allumni :-> ");
		scanf("%s",obj.cur_occ);
		printf("Enter current city of allumni :-> ");
		scanf("%s",obj.cur_city);
		printf("Enter recidential address of allumni (without a single space) :-> ");
		scanf("%s",obj.address);
		printf("Enter aadhaar number of allumni :-> ");
		scanf("%s",obj.uidai);
		printf("Enter contact number of allumni :-> ");
		scanf("%s",obj.mob_no);

		printf("Enter a short review (under 500 characters only) :->\n\nINSTRUCTION : Type your review and then press \'$\' to Save.\n\n");
		getchar();
		fgets(obj.rev,500,stdin);
		fwrite(&obj,sizeof(struct all_detail),1,allumni);
		printf("\nPress 1 to Add details of another allumni.\nPress 2 to return to previous window.");
		choice=getche();
	}while(choice=='1');
	fclose(allumni);
	Allumni();
}
void View_all_list()
{
	int sr=1;
	FILE *allumni;
	struct all_detail obj;
	Intro();
	printf("BCA Department > Allumni\'s portal > List view >");
	allumni=fopen("Allum_Database","rb");
	fread(&obj,sizeof(struct all_detail),1,allumni);
	printf("\nS.No.\t\tName of allumni\t\tPassing Year\t\tOccupation\n");
	while(!feof(allumni))
	{
		printf("%d\t\t%s %s\t\t%d\t\t%s\n",sr,obj.all_fir_nm,obj.all_lst_nm,obj.pass_yr,obj.cur_occ);
		fread(&obj,sizeof(struct all_detail),1,allumni);
		if(sr%16==0)
		{
			Intro();
			printf("BCA Department > Allumni\' portal > List view >\n");
		}
		sr++;
	}
	printf("Press any Key to Continue.");
	getch();
	fclose(allumni);
	Allumni();
}
void Search_all()
{
	int a,i;
	char first[15],last[15];
	FILE *allumni;
	struct all_detail obj;
	Intro();
	printf("BCA Department > Allumni\'s portal > Search complete details >");
	printf("\nEnter first and last name of allumni :-> ");
	scanf("%s%s",first,last);
	allumni=fopen("Allum_Database","rb");
	fread(&obj,sizeof(struct all_detail),1,allumni);
	while(!feof(allumni))
	{
		if(!(stricmp(first,obj.all_fir_nm)&&stricmp(last,obj.all_lst_nm)))
		{
			printf("\n1.) Enter first and last name of allumni :-> %s %s",obj.all_fir_nm,obj.all_lst_nm);
			printf("\n2.) Enter first and last name of allumni\'s father :-> %s %s",obj.all_fat_fir_nm,obj.all_fat_lst_nm);
			printf("\n3.) Enter course session :-> %s",obj.course_session);
			printf("\n4.) Enter passing year of allumni :-> %d",obj.pass_yr);
			printf("\n5.) Enter current occupation of allumni :-> %s",obj.cur_occ);
			printf("\n6.) Enter current city of allumni :-> %s",obj.cur_city);
			printf("\n7.) Enter recidential address of allumni (without a single space) :-> %s",obj.address);
			printf("\n8.) Enter aadhaar number of allumni :-> %s",obj.uidai);
			printf("\n9.) Enter contact number of allumni :-> %s",obj.mob_no);
			printf("\n10.) Review of allumni :->\n");
			printf("%s",obj.rev);
			getch();
			}

			fread(&obj,sizeof(struct all_detail),1,allumni);

	}
	fclose(allumni);
	Allumni();
}
