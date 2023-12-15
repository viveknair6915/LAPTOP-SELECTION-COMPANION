#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int tz=1;
//main project structure:-
struct lap_find
{
char lap_name[100];
char lap_proce[50];
int ram;
int storage;
char storage_type[100];
char lap_graphic[100];
float disp_size;
int price;
};
//function to print/display the laptops(will always be called inside a for loop)
void display(struct lap_find lap[],int i)
{
printf("Details for laptop %d\n",tz);
printf("Laptop Model Name : %s\n", lap[i].lap_name);
printf("Laptop processor Name : %s\n", lap[i].lap_proce);
printf("Laptop ram : %dGB\n", lap[i].ram);
printf("Laptop storage : %dGB\n", lap[i].storage);
printf("Laptop storage type : %s\n", lap[i].storage_type);
printf("Laptop graphics : %s\n", lap[i].lap_graphic);
printf("Laptop display size : %.1f inches\n", lap[i].disp_size);
printf("Laptop price : Rs%d\n\n", lap[i].price);
tz++;
}
//function to count no. of structure's array's elements within the budget range
int struc_element_count(struct lap_find l[],int budg1,int budg2,int c)
{
for(int i=0;i<145;i++){
if(l[i].price>budg1 && (l[i].price+999)<budg2){
c++;
}
}return c;
}
//substring function.
int string_search(char search_in_word[],char search_sub_word[]){
int i,j,l;
for (l = 0; search_sub_word[l] != '\0'; l++);
for (i = 0, j = 0; search_in_word[i] != '\0' && search_sub_word[j] != '\0'; i++)
{
if (search_in_word[i] == search_sub_word[j])
{
j++;
}
else
{
j = 0;
}
}
if (j == l)
{
return 1;
}
else
{
return 0;
}}
//function to check login credentials(if exists) otherwise registers user in the database
void login_check(char username[],char password[]){
int sd=0;
FILE* fp = fopen("users.txt", "r");
 if (fp == NULL) {
 printf("Error: Unable to open user database.\n");
 }
 char s_username[32];
 char s_password[32];
 while (fscanf(fp, "%s %s", s_username, s_password) == 2) {
 if (strcmp(username, s_username) == 0 && strcmp(password, s_password) == 0) 
{
 printf("Welcome Back!\nLogin successful!\n\n");
 fclose(fp);
 sd++;
 break;
 }
else{continue;}
 }
 fclose(fp);
 if(sd==0){
FILE* fp = fopen("users.txt", "a");
if (fp == NULL) {
printf("Error: Unable to open user database.\n");
}
fprintf(fp,"%s %s\n", username, password);
fclose(fp);
printf("You were not registred as the user.\nNow you are registered.\n\n");
fclose(fp);
 }
}
//function to print macbooks in the budget range.
void mac_lap(struct lap_find lapt[],int count){
int w=0;
for(int i=0;i<count;i++){
if(string_search(lapt[i].lap_name,"Apple")==1){
display(lapt,i);
printf("\n");
w++;
}}
if(w==0){
printf("There are no macs in your budget range!\n\n");
}
}
int main()
{
printf("\n*******************************************\n");
printf("WELCOME TO YOUR LAPTOP SELECTION COMPANION\n");
printf("*******************************************\n\n");
printf("Enter Username: ");
//taking input of username and password.
char username[32];
scanf("%s", username);
printf("Enter Password: ");
char password[32];
scanf("%s", password);
//calling the login check funtion
login_check(username,password);
//Details of the laptops as elements of structure's variable-array
struct lap_find lap[145]
={{"HP Pavilion 15","12th Gen Intel Core i5",8,512,"SSD ","Intel Iris Xe",15.6,63590},
{"HP Pavilion 14","12th Gen Intel Core i3",16,256,"SSD ","Intel Iris Graphics",14,68599},
{"HP Pavilion 13","12th Gen Intel Core i5",8,512,"HDD ","Intel Iris Xe Graphics",14,68599},
{"HP Pavilion 16","12th Gen Intel Core i5",32,512,"SSD ","AMD Radeon Graphics",16,68599},
{"HP 247 G8","AMD Ryzen 3",8,512,"SSD ","Integrated Intel UHD Graphics",14,29990},
{"Lenovo IdeaPad Flex 3 Chromebook","Intel Celeron N4500",4,64,"HDD ","Integrated Intel UHD Graphics",11.6,29957},
{"Acer Extensa 15 ","Intel Core i3",8,512,"SSD ","Integrated Intel UHD Graphics",15.6,34757},
{"Lenovo IdeaPad 3","11th Gen Intel Core",8,512,"SSD ","Intel Iris Xe Graphics",15.6,37877},
{"Lenovo ThinkBook 15","AMD Ryzen 3 5300U ",8,512,"SSD ","Intel Iris Xe Graphics",15.6,37877},
{"Dell Inspiron 3525 Laptop","AMD Athlon Silver 3050U",8,256,"SSD ","Radeon Graphics",15.6,31799},
{"Lenovo IdeaPad Slim 3","Intel Celeron N4020 4th Gen",8,256,"SSD ","null",15.6,26409},
{"Dell Vostro 3420 Laptop","Intel Core i3",8,256,"SSD ","null",14.0,36790},
{"Acer Extensa 15","11th Gen Intel Core i3",8,256,"SSD ","Intel UHD Graphics",15.6,32790},
{"HP 15s","AMD Athlon Silver 3050U",8,512,"SSD ","AMD Radeon Graphics",15.6,28990},
{"HP 15s-du3055TU","11th Gen Intel Core i3",8,1024,"SSD ","UHD Graphics",15.6,39990},
{"Lenovo IdeaPad 3","11th Gen Intel Core i3",8,512,"SSD ","null",15.6,37914},
{"Lenovo ThinkBook 15","AMD Ryzen 3 5300U",8,256,"SSD ","null",15.6,33990},
{"Lenovo IdeaPad Slim 1","AMD Ryzen 3 3250U",8,512,"SSD ","null",15.6,31828},
{"HP 250 G8","11th Gen Intel Core i3",8,512,"SSD ","Intel UHD Graphics",15.6,35621},
{"HP 14s","11th Gen Intel Core i3",8,256,"SSD ","Intel UHD Graphics",14,33990},
{"Lenovo IdeaPad Slim 1","AMD Ryzen 5 3500U",8,512,"SSD ","null",15.6,38531},
{"Lenovo IdeaPad Slim 3","Intel Core i3",8,512,"HDD ","null",15.6,38700},
{"ASUS VivoBook 15","10th Gen Intel Core i3",8,512,"SSD ","integrated Graphics",15.6,33545},
{"HP 15s","AMD Ryzen 3- 5300U",8,512,"SSD ","Radeon Graphics",15.6,38577},
{"HP 15s-gr0012AU","AMD Ryzen 3-3250U",8,512,"SSD ","AMD Radeon Graphics",15.6,39999},
{"ASUS Vivobook 15","AMD Ryzen 5 3500U",8,512,"SSD ","Integrated Graphics",15.6,38809},
{"Lenovo IdeaPad Slim 3","11th Gen Intel Core i3",8,512,"SSD ","null",14,38500},
{"HP G8","11th Gen Core i3",8,512,"SSD ","null",14,35028},
{"HP 14s","11th Gen Intel Core i3",8,256,"SSD ","Intel UHD Graphics",14,33990},
{"Lenovo IdeaPad Slim 3","11th Gen Intel Core i3",8,512,"SSD ","null",15.6,37990},
{"HP 255 G8 Notebook","AMD Ryzen 3 3250U",8,512,"SSD ","null",15.6,31672},
{"HP 15s","Ryzen 3 3250U",8,512,"SSD ","AMD Radeon Graphics",15.6,34990},
{"Acer Aspire 3","Intel Core i3 11th Gen",8,512,"SSD ","null",15.6,37638},
{"Dell Vostro 3420","Intel Core i3",8,512,"SSD ","null",15.6,39990},
{"Lenovo IdeaPad Slim 3","Intel Core i3 10th Gen",4,256,"SSD ","null",14,31990},
{"Dell New 15","Intel core i3",8,256,"SSD ","Integrated Graphics",39929},
{"Dell Intel LATITUDE 7490","Pro - CORE i7 8TH GEN",8,512,"SSD ","null",15.6,31190},
{"ASUS VivoBook 15","Intel Core i3 11th Gen",8,512,"SSD ","Integrated Graphics",15.6,36990},
{"Acer One 14 Business Laptop","AMD Ryzen 5 3500U",16,512,"SSD ","AMD Radeon Graphics",14,39990},
{"HP 15s","11th Gen Intel Core i3",8,512,"SSD ","Intel UHD Graphics",15.6,41968},
{"HP ProBook 440 G8Notebook PC","11th Gen Intel Core i5",8,512,"SSD ","Intel Irix Xe Graphics",14,49990},
{"Lenovo Ideapad 3","AMD Ryzen 5 5500U",8,512,"SSD ","null",15.6,44828},
{"Dell 2in1 Inspiron 7420 Laptop","Intel Core i3-1215U",8,256,"SSD ","null",15.6,49990},
{"HP 14s","AMD Ryzen 5-5500U",8,512,"SSD ","Radeon Graphics",15.6,47821},
{"ASUS Vivobook 16X (2022)","AMD Ryzen 5 5600H",8,512,"SSD ","Integrated Graphics",16,49990},
{"Dell Inspiron 3511 Laptop","Intel Core i3",8,512,"SSD ","null",40517},
{"ASUS Vivobook 14","Intel Core i510th Gen",8,512,"SSD ","Integrated Graphics",15.6,42400},
{"HP 15s","11th Gen Intel Core i3",8,512,"SSD ","Intel UHD Graphics",15.6,40990},
{"HP Pavilion 15","AMD Ryzen 5",8,512,"SSD ","null",15.6,49999},
{"Lenovo V15","Intel Core i5 11th Gen",8,512,"SSD ","null",15.6,49890},
{"HP 15s","11th Gen Intel Core i3",8,256,"SSD ","Intel UHD Graphics",15.6,41990},
{"Dell Inspiron 3520 Laptop","Intel Core i3",8,512,"SSD ","null",15.6,46000},
{"ASUS VivoBook 14","Intel Core i5-1135G7 11th Gen",8,256,"SSD ","Integrated Graphics",14,43790},
{"HP 250 G8 Laptop","11th Gen Intel Core i3",8,512,"SSD ","Intel UHD Graphics",15.6,35621},
{"HP Victus Gaming Latest","AMD Ryzen 5 5600H",8,512,"SSD","Geforce GTX 1650",16.1,59990},
{"Samsung Galaxy Book2","Intel 12th Gen core i5",8,512,"SSD","null",15.6,59990},
{"HP Victus Gaming Latest","AMD Ryzen 5 5600H Processor",8,512,"SSD","Radeon RX5500M Graphics",16.1,56990},
{"ASUS TUF Gaming F15","Intel Core i5-10300H 10th Gen",8,512,"SSD","NVIDIA GeForce GTX 1650",15.6,56990},
{"Acer Aspire 3","core i5 11th Generation Processor",8,1024,"HDD","Intel Iris Xe Graphic",51775},
{"Acer Aspire Vero","Intel Core i5 11th Gen",8,512,"SSD","null",15.6,50916},
{"HP Pavilion Gaming","AMD Ryzen 5-3550",8,1024,"HDD","NVIDIA GTX 1650",15.6,59000},
{"Acer Aspire 5","Intel Core i5 11th Generation",8,512,"SSD","Iris Xe Graphics",14,58499},
{"HP 14 Laptop","Ryzen 5 3500U",8,512,"SSD","Radeon Vega 8 Graphics",14,56500},
{"ASUS TUF Gaming A15","AMD Ryzen 5 4600H",8,512,"SSD","NVIDIA GeForce GTX 1650",15.6,56990},
{"HP 15s","12th Gen Intel Core i5",16,512,"SSD","Intel Iris Xe Graphics",15.6,60999},
{"Lenovo IdeaPad Slim 5","AMD Ryzen 7 5700U",16,512,"SSD","null",15.6,65627},
{"Acer Nitro 5 Gaming Laptop","Intel Core i5 11th Gen Processor",16,512,"SSD","NVIDIA GeForce GTX 1650 Graphics",15.6,61990},
{"Lenovo IdeaPad Slim 5i","11th Gen Intel Core i5",8,512,"SSD","MX450 2GB GDDR6",15.6,67990},
{"Lenovo IdeaPad Slim 5","11th Gen Intel Core i5",8,512,"SSD","Integrated Graphics",15.6,64200},
{"HP Victus Gaming Latest","AMD Ryzen 5-5600H Processor",8,512,"SSD","Geforce RTX 3050 Graphics",15.6,68990},
{"HP 15","11th Gen Intel Core i5",8,512,"SSD","Intel Iris Xe Graphics",15.6,61000},
{"Lenovo IdeaPad Gaming 3","Intel Core i5 11th Gen",16,512,"SDD","NVIDIA RTX 3050",15.6,66490},
{"Lenovo IdeaPad Gaming 3","Intel Core i5 11th Gen",8,512,"SDD","NVIDIA RTX 3050",15.6,62490},
{"Acer Nitro 5 AN515-56","11th Gen Intel Core i5-11300H",8,512,"SSD","NVIDIA GeForce GTX 1650 Graphics",15.6,61500},
{"MSI Katana GF66 Thin","Intel 12th Gen. i7 12450H",16,512,"SSD","Nvidia RTX 3050Ti",15.7,76990},
{"HP Pavilion Laptop 15","12th Gen Intel Core i5-1235U",16,512,"SSD","NVIDIA GeForce MX550 Graphics",15.6,75070},
{"ASUS TUF Dash F15","Intel Core i5-12450H 12th Gen",8,512,"SSD","RTX 3050 Graphics",15.6,78890},
{"ASUS TUF Gaming A15","AMD Ryzen 7 4800H",16,512,"SSD","GeForce RTX 3050 Graphics",15.6,77890},
{"Lenovo IdeaPad Gaming 3","AMD Ryzen 7 5800H",8,512,"SSD","NVIDIA RTX 3050",15.6,73990},
{"HP Victus","AMD Ryzen 7 5800H",16,512,"SSD","GeForce RTX 3050 Graphics",16.1,78950},
{"HP OMEN","AMD Ryzen 5-4600H",8,512,"SSD","NVIDIA 1650ti Graphics",15.6,78999},
{"HP 14","10th Gen Intel Core i5",8,256,"SSD","null",14,78400},
{"ASUS ZenBook 13","Intel Evo Core i5-1135G7 11th Gen",8,512,"SSD","Iris Xe Graphics",13.3,75999},
{"Acer Nitro 5","AN515-57 Intel Core i5-11400H",8,256,"SSD","NVIDIA GeForce RTX 3050 Graphics",15.6,78000},
{"HP Victus Gaming","Latest 12th Gen Intel Core i7",8,512,"SSD","RTX 3050 Graphics",15.6,84990},
{"ASUS ZenBook Duo 14 2021","Intel Core i5-1135G7",8,512,"SSD","Iris Xe Graphics",14,80990},
{"ASUS ZenBook 14","Intel Core i5",8,512,"SSD","NVIDIA GeForce MX250 Graphics",14,83590},
{"Acer Nitro 5","12th Intel Core i5",16,512,"SSD","RTX 3050 Graphics",15.6,84990},
{"HP Victus Gaming","AMD Ryzen 7-5800H",16,512,"SSD","RTX 3050 Graphics",16.1,81968},
{"ASUS ROG Strix G17","AMD Ryzen 7 4800H",16,1024,"SSD","RTX 3050 Ti Graphics",17.3,85990},
{"ASUS Zenbook 14","AMD Ryzen 5 5600H",16,512,"SSD","Integrated Graphics",14,89238},
{"Hp Pavilion 15","12Th Gen Intel Core I7",16,1024,"Ssd","Intel Iris Xe Graphics",15.6,89999},
{"ASUS ZenBook 13","Intel Core i7-1165G7 11th Gen",16,1024,"SSD","Intel Iris Graphics",13.3,85990},
{"ASUS ZenBook 14","Intel Core i7-1165G7 11th Gen",16,512,"SSD","Iris Xe Graphics",14,82999},
{"HP Pavilion Plus","12th Gen Intel Core i7",16,1024,"SSD","Intel Iris Xe Graphics",14,94630},
{"Samsung Galaxy Book2","Intel 12th Gen i5 EvoTM",16,512,"SSD","null",13.3,94990},
{"Samsung Galaxy Book2 Pro","Intel 12th Gen i5 EvoTM",16,512,"SSD","null",13.3,95500},
{"HP Pavilion Plus","12th Gen Intel Core i7",16,1024,"SSD","Intel Iris Xe Graphics",14,94630},
{"ASUS TUF Gaming A15","AMD Ryzen 7 6800H",16,512,"SSD","RTX 3060 Graphics",15.6,94990},
{"ASUS Zenbook 14","Intel Core Evo i7-1260P 12th Gen",16,512,"SSD","null",14,97534},
{"Acer Nitro 5","Intel core i7 11th Gen",16,512,"SSD","NVIDIA  GeForce RTX 3050 Ti",15.6,99990},
{"Lenovo ThinkBook 15","Intel 12th Gen Core i7",16,1024,"SSD","null",15.6,91490},
{"ASUS TUF Dash F15","Intel Core i7-12650H 12th Gen",16,512,"SSD","RTX 3050 Graphics",15.6,94900},
{"ASUS Vivobook Pro 16","Intel Core i9-11900H 11th Gen",16,512,"SSD","RTX 3050",16,99990},
{"Acer Nitro 5","12th Gen Intel Core i7-12700H",16,512,"SSD","RTX 3050Ti Graphics",15.6,104118},
{"Samsung Galaxy Book2 Pro","Intel 12th Gen i7 EvoTM",16,512,"SSD","null",13.3,109990},
{"Apple MacBook Air Laptop","M2 chip",8,256,"SSD","null",13.6,105890},
{"Lenovo IdeaPad Gaming 3","Intel Core i7-12700H",16,512,"SSD","NVIDIA RTX 3060",16,104990},
{"HP Victus","11th Gen Intel Core i7-11800H",16,512,"SSD","GeForce RTX 3060 Graphics",16.1,106440},
{"Lenovo ThinkPad E14","Intel Core i7 12th Gen 14",16,1024,"SSD","null",14,102490},
{"Acer Nitro 5","12th Gen Intel Core i7-12700H",16,512,"SSD","RTX 3050Ti Graphics",15.6,104118},
{"HP Spectre X360","12th Gen Intel Evo Core i5",16,512,"SSD","null",13.5,104500},
{"Lenovo ThinkPad P14s","11th Gen Intel Core i7",16,512,"SSD","null",14,109990},
{"Dell New G15-5515","AMD Ryzen7-5800H",16,512,"SSD","Nvidia RTX 3060",15.6,106890},
{"Lenovo Legion 5","AMD Ryzen 7 5800H",16,512,"SSD","NVIDIA RTX 3060",15.6,116500},
{"Apple MacBook Air Laptop","M2 chip",8,256,"SSD","null",13.6,111490},
{"ASUS TUF Gaming F15","Intel Core i7-12700H 12th Gen",16,1024,"SSD","RTX 3060 Graphics",15.6,118000},
{"Lenovo IdeaPad Gaming 3","Intel Core i7-12700H",16,512,"SSD","NVIDIA RTX 3060",16,104990},
{"Lenovo Yoga 7","Intel Evo i7",16,512,"SSD","null",14,111931},
{"Samsung Galaxy Book2 Pro","Intel 12th Gen i7 EvoTM",16,512,"SSD","null",15.6,117990},
{"HP Envy 15","11th Gen Intel Core i7",16,1024,"SSD","NVIDIA GeForce RTX 3050 Graphics",15.6,116899},
{"Lenovo Legion 5","Intel Core i7 11th Gen",16,512,"SSD","NVIDIA RTX 3050",15.6,117990},
{"Lenovo IdeaPad Gaming 3","Intel Core i7-12700H",16,512,"SSD","NVIDIA RTX 3060",16,114990},
{"HP Victus","11th Gen Intel Core i7-11800H",16,512,"SSD","GeForce RTX 3060 Graphics",16.1,116440},
{"Apple MacBook Air Laptop","Apple M1 chip",8,256,"SSD","Apple integrated graphics",13.3,86990},
{"Apple MacBook Air Laptop","Apple M2 chip",8,512,"SSD","Apple integrated graphics",13.3,140990},
{"Apple MacBook Pro","Apple M1 Max chip with 10core CPU and 32core GPU",32,1024,"SSD","Apple integrated graphics",16,307990},
{"Apple MacBook Pro","Apple M1 Pro chip with 10core CPU and 16core GPU",16,1024,"SSD","Apple integrated graphics",14,222990},
{"Apple MacBook Pro","Apple M1 Pro chip with 10core CPU and 16core GPU",16,1024,"SSD","Apple integrated graphics",16,242990},
{"Apple MacBook Pro","Apple M1 Pro chip with 8core CPU and 14core GPU",16,512,"SSD","Apple integrated graphics",14,181990},
{"ASUS TUF Gaming F15","Core i9 11th Gen",16,1024,"SSD","NVIDIA GeForce RTX 3060",15.6,122990},
{"Acer Predator Helios 300","Core i9 11th Gen",16,1024,"SSD","NVIDIA GeForce RTX 3060",15.6,124990},
{"DELL Core i9","12th Gen",16,1024,"SSD","NVIDIA GeForce RTX 3060",15.6,151990},
{"ASUS Zenbook 14X Space Edition","Core i9 12th Gen",32,1024,"SSD","null",14,159990},
{"DELL Core i9","12th Gen",16,1024,"SSD","NVIDIA GeForce RTX 3070 Ti",15.6,180990},
{"ASUS ROG Zephyrus G14","AMD Ryzen 9 6900HS",16,1024,"SSD","RX 6700S Graphics",14,154110},
{"ASUS ROG Strix Scar 15","AMD Ryzen 9 5900HX",16,1024,"SSD","RTX 3080 Graphics",15.6,199990},
{"ASUS ROG Zephyrus Duo 16 Dual Screen Laptop","AMD Ryzen 9 6900HX",32,2048,"SSD","RTX 3080 Ti Graphics",1.56,396990},
{"ASUS Vivobook Pro 14X OLED DialPad","AMD Ryzen 9 5900HX",16,1024,"SSD","RTX 3050 Ti Graphics",14,101990},
{"ASUS ROG Strix G17","AMD Ryzen 9 6900HX",16,1024,"SSD","RTX 3080 Graphics",17.3,210990},
{"ASUS ROG Zephyrus Duo 16 Dual Screen Laptop","AMD Ryzen 9 6900HX",32,2048,"SSD","RTX 3080 Ti Graphics",16,405990},
{"ASUS ROG Zephyrus G14","AMD Ryzen 9 5900HS",16,1024,"SSD","RTX 3050 Ti Graphics",16,130000},
{"HP Omen","AMD Ryzen 9",16,1024,"SSD","Rx 6600M Graphics",16.1,127680},
{"HP Omen 9th Gen","AMD Ryzen 6900HX",32,1024,"SSD","AMD Radeon RX 6650M Graphics",16.1,160180},
{"ASUS VivoBook Pro 16X OLED","AMD Ryzen 9-5900HX",16,1024,"SSD","RTX 3050 Graphics",16.1,145000},
};
//Taking user input budget range.
//c=0 for calling count function.
int budg1,budg2,c=0;
printf("Enter you Budget range-\npreferrably in ranges of 10000's to get more filtered results (format is 'x-y\'): ");
scanf("%d-%d",&budg1,&budg2);
//error handling for wrong budget range.
if(budg2<25000){
printf("Sorry we dont have Laptop Less than<=%d\nPlease enter a higher budget range\n",budg2);
return 0;
}
int j=0;
//defining new structure variable lapt which contains details of only those laptops which are inside the budget range.
struct lap_find lapt[struc_element_count(lap,budg1,budg2,c)];
//copying details of all laptops within budget range from lap to lapt
for(int i=0;i<145;i++){if(lap[i].price>budg1 && (lap[i].price+999)<budg2){
lapt[j]=lap[i];
j++;
}
}
int count_lapt=struc_element_count(lapt,budg1,budg2,c);
//g=0; defined for strcmp comparisons and then else case of questions
int g=0;
//q[50] defined for choices
int q[50];
printf("------------------------------------------------------------------------------\n");
printf("What do you mostly do with your laptop?\n");
printf("Choose from-----------------------\n");
printf("1.Content Creation(high performance laptops)\n");
printf("2.Browsing and Email(basic office work)\n");
printf("3.Business(slim and portable high performance laptops)\n");
printf("4.Gaming(such laptops are suitable for intensive taska but are not veryportable)\n");
printf("5.Entertainment and Light Work((thin and light laptops with basic tasks)\n");
printf("6.Coding and College Work(portable performance laptops)\n");
printf("Enter your choice: ");
scanf("%d",&q[0]);
if(q[0]==1){
printf("What kind of tech aspects does your content utilise?\n");
printf("1.Photo Editing\n");
printf("2.Video Editing or Animation work \n");
printf("3.Graphic Desinging\n");
printf("4.More than one of the above\n");
printf("Enter you choice: ");
scanf("%d",&q[1]);
printf("\n");
//for photo editing use
if(q[1]==1)
{ g=0;
printf("\nYou use softwares like:--------------------\n");
printf("1.Adobe Photoshop\n");
printf("2.CorelDraw\n");
printf("3.GIMP etc.\n");
printf("Macbooks in your budget range are:\n\n ");
mac_lap(lapt,count_lapt);
printf("\nWindows Laptops in your budget range are:\n\n ");
for(int i=0;i<count_lapt;i++){
if(string_search(lapt[i].lap_proce,"i9")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 9")==1){
if(string_search(lapt[i].lap_graphic,"RTX")==1){
if(lapt[i].ram==16||lapt[i].ram==32){
display(lapt,i);
g++;
}
else{continue;}
}
else{continue;}
}
else if(string_search(lapt[i].lap_proce,"i7")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 7")==1){
if(string_search(lapt[i].lap_graphic,"Iris")==1 || 
string_search(lapt[i].lap_graphic,"Radeon")==1||
string_search(lapt[i].lap_graphic,"RTX")==1){
if(lapt[i].ram==16||lapt[i].ram==32){
display(lapt,i);
g++;
}
else{continue;}
}
else{continue;}
}
else 
if(string_search(lapt[i].lap_proce,"i5")==1||string_search(lapt[i].lap_proce,"Ryzen 5")==1){
if(string_search(lapt[i].lap_graphic,"Iris")==1 || 
string_search(lapt[i].lap_graphic,"Radeon")==1||
string_search(lapt[i].lap_graphic,"RTX")==1){
if(lapt[i].ram==16||lapt[i].ram==32){
display(lapt,i);
g++;}
else{continue;}
}
else{continue;}
}
else{continue;}}
if(g==0){
printf("Laptops available in your Budget range dont fit your case well.\n");
printf("Please try a higher budget range.\n");
}
}
//for video Editing
else if(q[1]==2){
printf("what softwares do you use?:------------------\n");
printf("1.Final Cut Pro X(mac)\n");
printf("2.Adobe Premier Pro,DaVinci Resolve or similar apps.\n");
printf("3.ProCreate,Blender,Adobe Animate or similar apps.\n");
printf("Enter you choice: ");
scanf("%d",&q[2]);
printf("\n");
if(q[2]==1){
printf("Macbooks in your budget range are:\n ");
mac_lap(lapt,count_lapt);
}
else if(q[2]==2||q[2]==3){
g=0;
printf("Windows Laptops in your budget range are:\n ");
for(int i=0;i<count_lapt;i++){
if(string_search(lapt[i].lap_proce,"i9")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 9")==1){
if(string_search(lapt[i].lap_graphic,"RTX")==1){
if(lapt[i].ram==16||lapt[i].ram==32){
display(lapt,i);
g++;}
else{continue;}
}
else{continue;}
}
else if(string_search(lapt[i].lap_proce,"i7")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 7")==1){
if(string_search(lapt[i].lap_graphic,"Iris")==1 || 
string_search(lapt[i].lap_graphic,"Radeon")==1||
string_search(lapt[i].lap_graphic,"RTX")==1){
if(lapt[i].ram==16||lapt[i].ram==32){
display(lapt,i);
g++;}
else{continue;}
}
else{continue;}
}
else{continue;}
}
if(g==0){
printf("Laptops available in your Budget range dont fit your case well.\n");
printf("Please try a higher budget range.\n");
}
}
}
else if(q[1]==3){
g=0;
printf("You use softwares like?:--------------------\n");
printf("1.Adobe Illustrator\n");
printf("2.Adobe Photoshoop\n");
printf("3.Procreate etc.\n");
printf("Macbooks in your budget range are:\n ");
mac_lap(lapt,count_lapt);
printf("Windows Laptops in your budget range are:\n ");
for(int i=0;i<count_lapt;i++){
if(string_search(lapt[i].lap_proce,"i9")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 9")==1){
if(string_search(lapt[i].lap_graphic,"RTX")==1){
if(lapt[i].ram==16||lapt[i].ram==32){
display(lapt,i);
g++;}
else{continue;}
}
else{continue;}
}
else if(string_search(lapt[i].lap_proce,"i7")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 7")==1){
if(string_search(lapt[i].lap_graphic,"Iris")==1 || 
string_search(lapt[i].lap_graphic,"Radeon")==1||
string_search(lapt[i].lap_graphic,"RTX")==1){
if(lapt[i].ram==16||lapt[i].ram==32){
display(lapt,i);
}
else{continue;}
}
else{continue;}
}
else if(string_search(lapt[i].lap_proce,"i5")==1|| 
string_search(lapt[i].lap_proce,"Ryzen 5")==1){
if(string_search(lapt[i].lap_graphic,"Iris")==1 || 
string_search(lapt[i].lap_graphic,"Radeon")==1||
string_search(lapt[i].lap_graphic,"RTX")==1){
if(lapt[i].ram==16||lapt[i].ram==32){
display(lapt,i);
g++;}
else{continue;}
}
else{continue;}
}
else{continue;}}
if(g==0){
printf("Laptops available in your Budget range dont fit your case well.\n");
printf("Please try a higher budget range.\n");
}
}
else if(q[1]==4){
g=0;
printf("Macbooks in your budget range are:\n ");
mac_lap(lapt,count_lapt);
printf("\n");
printf("Windows Laptops in your budget range are:\n ");
for(int i=0;i<count_lapt;i++){
if(string_search(lapt[i].lap_proce,"i9")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 9")==1){
if(string_search(lapt[i].lap_graphic,"RTX")==1){
if(lapt[i].ram==16||lapt[i].ram==32){
display(lapt,i);
g++;}
else{continue;}
}
else{continue;}
}
else if(string_search(lapt[i].lap_proce,"i7")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 7")==1){
if(string_search(lapt[i].lap_graphic,"Iris")==1 || 
string_search(lapt[i].lap_graphic,"Radeon")==1||
string_search(lapt[i].lap_graphic,"RTX")==1){
if(lapt[i].ram==16||lapt[i].ram==32){
display(lapt,i);
g++;}
else{continue;}
}
else{continue;}
}
else{continue;}}
if(g==0){
printf("Laptops available in your Budget range dont fit your case well.\n");
printf("Please try a higher budget range.\n");
}
}
}
//Browsing and mailing laptops
else if(q[0]==2){
g=0;
printf("Macbooks in your budget range are:\n ");
mac_lap(lapt,count_lapt);
printf("Windows Laptops in your budget range are:\n");
printf("Make your decision based on the fact that:\n");
printf("1. Higher the Gen and i3/5/7/9 better the performance\n");
printf("(In some cases like(11th Gen i7 vs 12th Gen i; \n");
printf("both will give similar performance so take decision based on other factors.\n))");
printf("2. For Graphics(if you desire so) NVIDIA > Radeon=Iris > Integrated or UHD\n");
printf("3. For ram more the GB's the better efficiency \n");
printf("Macbooks in your budget range are:\n ");
mac_lap(lapt,count_lapt);
printf("Windows Laptops in your budget range are:\n ");
for(int i=0;i<count_lapt;i++){
if(string_search(lapt[i].lap_proce,"i9")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 9")==1){
display(lapt,i);
g++;}
else if(string_search(lapt[i].lap_proce,"i7")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 7")==1){
display(lapt,i);
g++;}
else 
if(string_search(lapt[i].lap_proce,"i5")==1||string_search(lapt[i].lap_proce,"Ryzen 5")==1){
display(lapt,i);
g++;}
else 
if(string_search(lapt[i].lap_proce,"i3")==1||string_search(lapt[i].lap_proce,"Ryzen 3")==1){
display(lapt,i);
g++;}
else{continue;}}
if(g==0){
printf("Laptops available in your Budget range dont fit your case well.\n");
printf("Please try a higher budget range.\n");
}
printf("If choices seem too much Use above guidelines to compare.");
}
//Business laptops
else if(q[0]==3){
g=0;
printf("Macbooks in your budget range are:\n ");
mac_lap(lapt,count_lapt);
printf("Windows Laptops in your budget range are:\n ");
for(int i=0;i<count_lapt;i++){
if(string_search(lapt[i].lap_proce,"i9")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 9")==1){
if(string_search(lapt[i].lap_graphic,"Iris")==1 || 
string_search(lapt[i].lap_graphic,"Radeon")==1||
string_search(lapt[i].lap_graphic,"RTX")==1){
display(lapt,i);
g++;}
else{continue;}
}
else if(string_search(lapt[i].lap_proce,"i7")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 7")==1){
if(string_search(lapt[i].lap_graphic,"Iris")==1 || 
string_search(lapt[i].lap_graphic,"Radeon")==1||
string_search(lapt[i].lap_graphic,"RTX")==1||string_search(lapt[i].lap_graphic,"UHD")==1){
display(lapt,i);
g++;}
else{continue;}
}
else 
if(string_search(lapt[i].lap_proce,"i5")==1||string_search(lapt[i].lap_proce,"Ryzen 5")==1){
if(string_search(lapt[i].lap_graphic,"Iris")==1 || 
string_search(lapt[i].lap_graphic,"Radeon")==1||
string_search(lapt[i].lap_graphic,"RTX")==1||string_search(lapt[i].lap_graphic,"UHD")==1){
display(lapt,i);
g++;}
else{continue;}
}
else{continue;}}
if(g==0){
printf("Laptops available in your Budget range dont fit your case well.\n");
printf("Please try a higher budget range.\n");
}
}
//gaming laptops
else if(q[0]==4){
printf("What type of games do you enjoy playing?:\n");
printf("1.GTA 5/Cyberpunk 2077/Red Dead Redemption etc\n");
printf("2.Forza Horizon/Tomb Raider/Need For speed etc\n");
printf("3.Among Us/Minecraft?Hotline Miami etc\n");
printf("4. GTA VC/GTA San Andreas etc. small games\n");
printf("ENter your choice: ");
scanf("%d",&q[3]);
printf("\n");
if(q[3]==1){
g=0;
printf("Windows Laptops in your budget range are:\n\n");
for(int i=0;i<count_lapt;i++){
if(string_search(lapt[i].lap_proce,"i9")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 9")==1){
if(string_search(lapt[i].lap_graphic,"RTX")==1){
if(lapt[i].ram==16||lapt[i].ram==32){
display(lapt,i);
g++;}
else{continue;}
}
else{continue;}
}
else if(string_search(lapt[i].lap_proce,"i7")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 7")){
if((string_search(lapt[i].lap_graphic,"RTX")==1)){
if(lapt[i].ram==16||lapt[i].ram==32){
display(lapt,i);
g++;}
else{continue;}
}
else{continue;}
}
else{continue;}}
if(g==0){
printf("Laptops available in your Budget range dont fit your case well.\n");
printf("Please try a higher budget range.\n");
}
}
else if(q[3]==2){
printf("Windows Laptops in your budget range are:\n ");
for(int i=0;i<count_lapt;i++){
if(string_search(lapt[i].lap_proce,"i9")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 9")==1){
if(string_search(lapt[i].lap_graphic,"RTX")==1){
if(lapt[i].ram==16||lapt[i].ram==32){
display(lapt,i);
g++;}
else{continue;}
}
else{continue;}
}
else if(string_search(lapt[i].lap_proce,"i7")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 7")==1){
if(string_search(lapt[i].lap_graphic,"RTX")==1){
if(lapt[i].ram==16||lapt[i].ram==32||lapt[i].ram==8){
display(lapt,i);
g++;}
else{continue;}
}
else{continue;}
}
else 
if(string_search(lapt[i].lap_proce,"i5")==1||string_search(lapt[i].lap_proce,"Ryzen 5")==1){
if(string_search(lapt[i].lap_graphic,"RTX")==1){
if(lapt[i].ram==16||lapt[i].ram==32){
display(lapt,i);
g++;}
else{continue;}
}
else{continue;}
}
else{continue;}}
if(g==0){
printf("Laptops available in your Budget range dont fit your case well.\n");
printf("Please try a higher budget range.\n");
}
}
else if(q[3]==3){
g=0;
printf("Windows Laptops in your budget range are:\n ");
for(int i=0;i<count_lapt;i++){
if(string_search(lapt[i].lap_proce,"i9")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 9")==1){
if(string_search(lapt[i].lap_graphic,"RTX")==1){
display(lapt,i);
g++;}
else{continue;}
}
else if(string_search(lapt[i].lap_proce,"i7")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 7")==1){
if(string_search(lapt[i].lap_graphic,"RTX")==1||string_search(lapt[i].lap_graphic,"Radeon")==1||
string_search(lapt[i].lap_graphic,"Iris")==1){
display(lapt,i);
g++;}
else{continue;}
}
else 
if(string_search(lapt[i].lap_proce,"i5")==1||string_search(lapt[i].lap_proce,"Ryzen 5")==1){
if(string_search(lapt[i].lap_graphic,"RTX")==1||string_search(lapt[i].lap_graphic,"Radeon")==1||
string_search(lapt[i].lap_graphic,"Iris")==1){
display(lapt,i);
g++;}
else{continue;}
}
else{continue;}}
if(g==0){
printf("Laptops available in your Budget range dont fit your case well.\n");
printf("Please try a higher budget range.\n");
}
}
else if(q[3]==4){
g=0;
printf("Macbooks in your budget range are:\n ");
mac_lap(lapt,count_lapt);
printf("Windows Laptops in your budget range are:\n ");
for(int i=0;i<count_lapt;i++){
if(string_search(lapt[i].lap_proce,"i9")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 9")==1){
display(lapt,i);
g++;}
else if(string_search(lapt[i].lap_proce,"i7")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 7")==1){
display(lapt,i);
g++;}
else 
if(string_search(lapt[i].lap_proce,"i5")==1||string_search(lapt[i].lap_proce,"Ryzen 5")==1){
display(lapt,i);
g++;}
else 
if(string_search(lapt[i].lap_proce,"i3")==1||string_search(lapt[i].lap_proce,"Ryzen 3")==1){
display(lapt,i);
g++;}
else{continue;}}
if(g==0){
printf("Laptops available in your Budget range dont fit your case well.\n");
printf("Please try a higher budget range.\n");
}
}
}
//laptops for entertainment and other work
else if(q[0]==5){
printf("For entertainment screen size is a important factor\n");
printf("What screen size do you prefer?\n");
printf("1.15.6\"\n");
printf("2.16\"\nEnter Choice 1/2: ");
scanf("%d",&q[4]);
printf("\n");
if(q[4]==1){
g=0;
printf("Macbooks in your budget range are:\n ");
for(int i=0;i<count_lapt;i++){
if(lapt[i].disp_size=15.6){
if(string_search(lapt[i].lap_name,"Apple")==1){
display(lapt,i);
printf("\n");
g++;
}}}
if(g==0);{printf("There are no macs in your budget range!\n");}
g=0;
printf("Windows Laptops in your budget range are:\n ");
for(int i=0;i<count_lapt;i++){
if(lapt[i].disp_size>=15.6){
if(string_search(lapt[i].lap_proce,"i9")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 9")==1){
display(lapt,i);
g++;}
else if(string_search(lapt[i].lap_proce,"i7")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 7")==1){
display(lapt,i);
g++;}
else 
if(string_search(lapt[i].lap_proce,"i5")==1||string_search(lapt[i].lap_proce,"Ryzen 5")==1){
display(lapt,i);
g++;}
else 
if(string_search(lapt[i].lap_proce,"i3")==1||string_search(lapt[i].lap_proce,"Ryzen 3")==1){
display(lapt,i);
g++;}
else{continue;}}}
if(g==0){
printf("Laptops available in your Budget range are not available in screen size 15.6\"\n");
printf("Please try a higher budget range.\n");
}
}
else if(q[4]==2){
g=0;
printf("Macbooks in your budget range are:\n ");
for(int i=0;i<count_lapt;i++){
if(lapt[i].disp_size>=16){
if(string_search(lapt[i].lap_name,"Apple")==1){
display(lapt,i);
printf("\n");
g++;
}}}
if(g==0);{printf("There are no macs in your budget range!\n");}
g=0;
printf("Windows Laptops in your budget range are:\n ");
for(int i=0;i<count_lapt;i++){
if(lapt[i].disp_size>=16){
if(string_search(lapt[i].lap_proce,"i9")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 9")==1){
display(lapt,i);
g++;}
else if(string_search(lapt[i].lap_proce,"i7")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 7")==1){
display(lapt,i);
g++;}
else 
if(string_search(lapt[i].lap_proce,"i5")==1||string_search(lapt[i].lap_proce,"Ryzen 5")==1){
display(lapt,i);
g++;}
else 
if(string_search(lapt[i].lap_proce,"i3")==1||string_search(lapt[i].lap_proce,"Ryzen 3")==1){
display(lapt,i);
g++;}
else{continue;}}}
if(g==0){
printf("Laptops available in your Budget range are not available in screen size 16\"\n");
printf("Please try a higher budget range.\n");
}
}}
//laptops for coding and college work
else if(q[0]==6){
printf("If you will purusue career in software Dev you will require a laptop in your budget range that can handle such tasks\n");
printf("And for other college work like note taking or email/browsing etc too these laptops will come in handy!\n");
printf("Macbooks in your budget range are:\n ");
mac_lap(lapt,count_lapt);
g=0;
printf("Windows Laptops in your budget range are:\n ");
for(int i=0;i<count_lapt;i++){
if(string_search(lapt[i].lap_proce,"i9")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 9")==1){
if(lapt[i].ram==16||lapt[i].ram==32||lapt[i].ram==8){
display(lapt,i);
g++;}
else{continue;}
}
else if(string_search(lapt[i].lap_proce,"i7")==1 || 
string_search(lapt[i].lap_proce,"Ryzen 7")==1){
if(lapt[i].ram==16||lapt[i].ram==32||lapt[i].ram==8){
display(lapt,i);
g++;}
else{continue;}
}
else 
if(string_search(lapt[i].lap_proce,"i5")==1||string_search(lapt[i].lap_proce,"Ryzen 5")==1){
if(lapt[i].ram==16||lapt[i].ram==32||lapt[i].ram==8){
display(lapt,i);
g++;}
else{continue;}
}
else 
if(string_search(lapt[i].lap_proce,"i3")==1||string_search(lapt[i].lap_proce,"Ryzen 3")==1){
if(lapt[i].ram==16||lapt[i].ram==32||lapt[i].ram==8){
display(lapt,i);
g++;}
else{continue;}
}
else{continue;}}
if(g==0){
printf("Laptops available in your Budget range are not available in screen size 16\"\n");
printf("Please try a higher budget range.\n");
}
}
else{printf("\nEntered choice is wrong.\nProgram terminates.\n\n");
}
return 0;
}
