#include <stdio.h>
#include <stdlib.h>

void flagfunction (char pos[3],int *firstflag, int* secondflag, char letter[8], char digit[8])
{
    int i = 0;
    printf("%d", sizeof(digit));
    for (i=0; i<= sizeof(letter)*2-1; i++)
    {
        if(pos[0]==letter[i])
            {*firstflag=1;
           // printf("pos[0] == letter[i]!");
            break;}

        printf("%c",letter[i]);
    }

    for (i=0; i<= sizeof(digit)*2-1; i++)
    {
        if(pos[1]==digit[i])
            {*secondflag=1;
          //  printf("pos[1] == digit[i]!");
            break;}
        printf("%c",digit[i]);
    }
    return 0;
}

int main()
{
    system("chcp 1251");
    int i = 0;
    char pos_king[3], pos_ladya1[3], pos_ladya2[3], pos_ladya3[3];
    char letter[8] = "abcdefgh";
    char digit[8] = "12345678";
    int firstflag=0, secondflag=0;
    int rightannotationflag=0;

    // attack flags. 0 - figure doesn't attack the king, 1 - castle attacks king by letters row, 2 - figure castle attacks king by digits line
    int first_ladya_attack_flag=0;
    int second_ladya_attack_flag=0;
    int third_ladya_attack_flag=0;

    while(rightannotationflag!=1)
 {

    printf("Enter kings position using standart e2 chess notations\n");
    scanf("%s", pos_king);

     flagfunction(pos_king,&firstflag, &secondflag, letter, digit);

    if ((firstflag==1)&&(secondflag==1)&&(pos_king[2]=='\0'))
    {
        rightannotationflag=1;
        printf("input is accepted, go on\n");
        printf("Third symbol is %c\n", pos_king[2]);
        firstflag = 0;
        secondflag = 0;
        rightannotationflag = 0;
        break;
    }
    else
        rewind(stdin);
}

     while(rightannotationflag!=1)
 {

    printf("Enter position of first white castle using standart chess e2 notation\n");
    scanf("%s", pos_ladya1);


    flagfunction(pos_ladya1,&firstflag, &secondflag, letter, digit);

    if ((firstflag==1)&&(secondflag==1)&&(pos_ladya1[2]=='\0'))
    {printf("Position of first castle: %s\n", pos_ladya1);
        if((pos_king[0]==pos_ladya1[0])&&(pos_king[1]==pos_ladya1[1]))
        {
            printf("Its imposible for two figures to stand in one cell\n");
            continue;
        }
        else{
            rightannotationflag=1;
            printf("input is correct, go on\n");
            printf("Third symbol is %c\n", pos_ladya1[2]);
            firstflag = 0;
            secondflag = 0;
            rightannotationflag = 0;
            break;
        }
    }
    else
        rewind(stdin);
}

     while(rightannotationflag!=1)
 {

    printf("Enter position of second white castle using standart chess e2 notation\n");
    scanf("%s", pos_ladya2);

    flagfunction(pos_ladya2,&firstflag, &secondflag, letter, digit);

    if ((firstflag==1)&&(secondflag==1)&&(pos_ladya2[2]=='\0'))
    {
        if(((pos_king[0]==pos_ladya2[0])&&(pos_king[1]==pos_ladya2[1]))||(((pos_ladya1[0])==pos_ladya2[0])&&(pos_ladya1[1]==pos_ladya2[1])))
        {
            printf("Its imposible for two figures to stand in one cell\n");
            continue;
        }
        else{
            rightannotationflag=1;
            printf("input is correct, go on\n");
            printf("Third symbol is %c\n", pos_ladya2[2]);
            firstflag = 0;if(third_ladya_attack_flag==2)
    {
        printf("Òðåòüÿ ëàäüÿ, íàõîäÿùàÿñÿ íà ïîçèöèè %s àòàêóå\n", pos_ladya3);
    }
            secondflag = 0;
            rightannotationflag = 0;
            break;
        }
    }
    else
        rewind(stdin);
}

     while(rightannotationflag!=1)
 {

    printf("Óêàæèòå ïîçèöèþ òðåòüåé ëàäüè, èñïîëüçóÿ ñòàíäàðòíóþ çàïèñü, íàïðèìåð e2\n");
    scanf("%s", pos_ladya3);

    flagfunction(pos_ladya3,&firstflag, &secondflag, letter, digit);

    if ((firstflag==1)&&(secondflag==1)&&(pos_ladya3[2]=='\0'))
    {
        if(((pos_king[0]==pos_ladya3[0])&&(pos_king[1]==pos_ladya3[1]))||(((pos_ladya1[0])==pos_ladya3[0])&&(pos_ladya1[1]==pos_ladya3[1]))||(((pos_ladya2[0])==pos_ladya3[0])&&(pos_ladya2[1]==pos_ladya3[1])))
        {
            printf("Íà îäíîé è òîé æå êëåòêå íå ìîæåò ñòîÿòü äâå ôèãóðû\n");
            continue;
        }
        else{
            rightannotationflag=1;
            printf("ââîä êîððåêòåí, ïðîäîëæàåì\n");
            printf("Third symbol is %c\n", pos_ladya3[2]);
            firstflag = 0;
            secondflag = 0;
            rightannotationflag = 0;
            break;
        }
    }
    else
        rewind(stdin);
}


    printf("Ïîçèöèÿ ÷åðíîãî êîðîëÿ: %s\n", pos_king);
    printf("Ïîçèöèÿ ïåðâîé ëàäüè: %s\n", pos_ladya1);
    printf("Ïîçèöèÿ âòîðîé ëàäüè: %s\n", pos_ladya2);
    printf("Ïîçèöèÿ òðåòüåé ëàäüè: %s\n", pos_ladya3);

    //àíàëèçèðóåì è ôîðìèðóåì ôëàãè àòòàê
    printf("àíàëèç ïîçèöèè ôèãóð \n");

    if (pos_king[0]==pos_ladya1[0])
        first_ladya_attack_flag=1;
    else if (pos_king[1]==pos_ladya1[1])
        first_ladya_attack_flag=2;
    else
        first_ladya_attack_flag=0;

    if (pos_king[0]==pos_ladya2[0])
        second_ladya_attack_flag=1;
    else if (pos_king[1]==pos_ladya2[1])
        second_ladya_attack_flag=2;
    else
        second_ladya_attack_flag=0;

    if (pos_king[0]==pos_ladya3[0])
        third_ladya_attack_flag=1;
    else if (pos_king[1]==pos_ladya3[1])
        third_ladya_attack_flag=2;
    else
        third_ladya_attack_flag=0;

    if (third_ladya_attack_flag==2&&second_ladya_attack_flag==2&&first_ladya_attack_flag==2)
       {
           printf("Âñå òðè ëàäüè ðàñïîëîæåíû íà îäíîé ëèíèè ïî ñòîëáöó öèôð è ñàìàÿ áëèçêà èç íèõ àòàêóåò êîðîëÿ\n");
           if (pos_king[0]<pos_ladya1[0]&&pos_king[0]<pos_ladya2[0]&&pos_king[0]<pos_ladya3[0])
           {
                printf("Âñå òðè àòàêóþùèå ëàäüè ñïðàâà îò êîðîëÿ\n");
                int min = pos_ladya1[0];
                if (min>pos_ladya2[0])
                   {
                       min = pos_ladya2[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;

                if (min>pos_ladya3[0])
                {
                    min = pos_ladya3[0];
                    second_ladya_attack_flag=0;
                }
                else
                    third_ladya_attack_flag=0;
           }
           else if (pos_king[0]>pos_ladya1[0]&&pos_king[0]>pos_ladya2[0]&&pos_king[0]>pos_ladya3[0])
           {
                printf("Âñå òðè àòàêóþùèå ëàäüè ñëåâà îò êîðîëÿ\n");
                int max = pos_ladya1[0];
                if (max<pos_ladya2[0])
                   {
                       max = pos_ladya2[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;

                if (max<pos_ladya3[0])
                {
                    max = pos_ladya3[0];
                    second_ladya_attack_flag=0;
                }
                else
                    third_ladya_attack_flag=0;
           }

           else if (pos_king[0]<pos_ladya1[0]&&pos_king[0]<pos_ladya2[0]&&pos_king[0]>pos_ladya3[0])
           {
                printf("äâå àòàêóþùèå ëàäüè ñïðàâà îò êîðîëÿ\n");
                int min = pos_ladya1[0];
                if (min>pos_ladya2[0])
                   {
                       min = pos_ladya2[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;
           }

           else if (pos_king[0]<pos_ladya1[0]&&pos_king[0]<pos_ladya3[0]&&pos_king[0]>pos_ladya2[0])
           {
                printf("äâå àòàêóþùèå ëàäüè ñïðàâà îò êîðîëÿ\n");
                int min = pos_ladya1[0];
                if (min>pos_ladya3[0])
                   {
                       min = pos_ladya3[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;
           }
           else if (pos_king[0]<pos_ladya2[0]&&pos_king[0]<pos_ladya3[0]&&pos_king[0]>pos_ladya1[0])
           {
                printf("äâå àòàêóþùèå ëàäüè ñïðàâà îò êîðîëÿ\n");
                int min = pos_ladya2[0];
                if (min>pos_ladya3[0])
                   {
                       min = pos_ladya3[0];
                       second_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;
           }

           else if (pos_king[0]>pos_ladya1[0]&&pos_king[0]>pos_ladya2[0]&&pos_king[0]<pos_ladya3[0])
           {
                printf("äâå àòàêóþùèå ëàäüè ñëåâà îò êîðîëÿ\n");
                int max = pos_ladya1[0];
                if (max<pos_ladya2[0])
                   {
                       max = pos_ladya2[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;
           }

           else if (pos_king[0]>pos_ladya1[0]&&pos_king[0]>pos_ladya3[0]&&pos_king[0]<pos_ladya2[0])
           {
                printf("äâå àòàêóþùèå ëàäüè ñëåâà îò êîðîëÿ\n");
                int max = pos_ladya1[0];
                if (max<pos_ladya3[0])
                   {
                       max = pos_ladya3[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;
           }
           else if (pos_king[0]>pos_ladya2[0]&&pos_king[0]>pos_ladya3[0]&&pos_king[0]<pos_ladya1[0])
           {
                printf("äâå àòàêóþùèå ëàäüè ñëåâà îò êîðîëÿ\n");
                int max = pos_ladya2[0];
                if (max>pos_ladya3[0])
                   {
                       max = pos_ladya3[0];
                       second_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;
           }
       }

    else if (first_ladya_attack_flag==2&&second_ladya_attack_flag==2)
       {
        printf("Äâå ëàäüè ðàñïîëîæåíû íà îäíîé ëèíèè ïî ñòîëáöó öèôð è ñàìàÿ áëèçêà èç íèõ àòàêóåò êîðîëÿ\n");
           if (pos_king[0]<pos_ladya1[0]&&pos_king[0]<pos_ladya2[0])
           {
                printf("Îáå àòàêóþùèå ëàäüè ñïðàâà îò êîðîëÿ\n");
                int min = pos_ladya1[0];
                if (min>pos_ladya2[0])
                   {
                       min = pos_ladya2[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;


           }

           else if (pos_king[0]>pos_ladya1[0]&&pos_king[0]>pos_ladya2[0])
           {
                printf("Îáå àòàêóþùèå ëàäüè ñëåâà îò êîðîëÿ\n");
                int max = pos_ladya1[0];
                if (max<pos_ladya2[0])
                   {
                       max = pos_ladya2[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;

           }
           else
            printf("äâå àòàêóþùèå ëàäüè ðàñïîëîæåíû ïî îáå ñòîðîíû îò êîðîëÿ\n");
       }

       else if (first_ladya_attack_flag==2&&third_ladya_attack_flag==2)
       {
        printf("Äâå ëàäüè ðàñïîëîæåíû íà îäíîé ëèíèè ïî ñòîëáöó öèôð è ñàìàÿ áëèçêà èç íèõ àòàêóåò êîðîëÿ\n");
           if (pos_king[0]<pos_ladya1[0]&&pos_king[0]<pos_ladya3[0])
           {
                printf("Îáå àòàêóþùèå ëàäüè ñïðàâà îò êîðîëÿ\n");
                int min = pos_ladya1[0];
                if (min>pos_ladya3[0])
                   {
                       min = pos_ladya3[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;


           }

           else if (pos_king[0]>pos_ladya1[0]&&pos_king[0]>pos_ladya3[0])
           {
                printf("Îáå àòàêóþùèå ëàäüè ñëåâà îò êîðîëÿ\n");
                int max = pos_ladya1[0];
                if (max<pos_ladya3[0])
                   {
                       max = pos_ladya3[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;

           }
           else
            printf("äâå àòàêóþùèå ëàäüè ðàñïîëîæåíû ïî îáå ñòîðîíû îò êîðîëÿ\n");
       }

       else if (second_ladya_attack_flag==2&&third_ladya_attack_flag==2)
       {
        printf("Äâå ëàäüè ðàñïîëîæåíû íà îäíîé ëèíèè ïî ñòîëáöó öèôð è ñàìàÿ áëèçêà èç íèõ àòàêóåò êîðîëÿ\n");
           if (pos_king[0]<pos_ladya2[0]&&pos_king[0]<pos_ladya3[0])
           {
                printf("Îáå àòàêóþùèå ëàäüè ñïðàâà îò êîðîëÿ\n");
                int min = pos_ladya2[0];
                if (min>pos_ladya3[0])
                   {
                       min = pos_ladya3[0];
                       second_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;


           }

           else if (pos_king[0]>pos_ladya2[0]&&pos_king[0]>pos_ladya3[0])
           {
                printf("Îáå àòàêóþùèå ëàäüè ñëåâà îò êîðîëÿ\n");
                int max = pos_ladya2[0];
                if (max<pos_ladya3[0])
                   {
                       max = pos_ladya3[0];
                       second_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;

           }
           else
            printf("äâå àòàêóþùèå ëàäüè ðàñïîëîæåíû ïî îáå ñòîðîíû îò êîðîëÿ\n");
       }

      if (third_ladya_attack_flag==1&&second_ladya_attack_flag==1&&first_ladya_attack_flag==1)
       {
           printf("Âñå òðè ëàäüè ðàñïîëîæåíû íà îäíîé ëèíèè ïî ñòîëáöó öèôð è ñàìàÿ áëèçêà èç íèõ àòàêóåò êîðîëÿ\n");
           if (pos_king[1]>pos_ladya1[1]&&pos_king[1]>pos_ladya2[1]&&pos_king[1]>pos_ladya3[1])
           {
                printf("Âñå òðè àòàêóþùèå ëàäüè ñâåðõó îò êîðîëÿ\n");
                int max = pos_ladya1[1];
                if (max<pos_ladya2[1])
                   {
                       max = pos_ladya2[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;

                if (max<pos_ladya3[1])
                {
                    max = pos_ladya3[1];
                    second_ladya_attack_flag=0;
                }
                else
                    third_ladya_attack_flag=0;
                    //ok
           }
           else if (pos_king[1]<pos_ladya1[1]&&pos_king[1]<pos_ladya2[1]&&pos_king[1]<pos_ladya3[1])
           {
                printf("Âñå òðè àòàêóþùèå ëàäüè ñíèçó îò êîðîëÿ\n");
                int min = pos_ladya1[1];
                if (min>pos_ladya2[1])
                   {
                       min = pos_ladya2[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;

                if (min>pos_ladya3[1])
                {
                    min = pos_ladya3[1];
                    second_ladya_attack_flag=0;
                }
                else
                    third_ladya_attack_flag=0;
                    //ok
           }
// äàëüøå ïåðåïðîâåðèòü
           else if (pos_king[1]>pos_ladya1[1]&&pos_king[1]>pos_ladya2[1]&&pos_king[1]<pos_ladya3[1])
           {
                printf("äâå àòàêóþùèå ëàäüè ñâåðõó îò êîðîëÿ\n");
                int max = pos_ladya1[1];
                if (max<pos_ladya2[1])
                   {
                       max = pos_ladya2[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;
           }

           else if (pos_king[1]>pos_ladya1[1]&&pos_king[1]>pos_ladya3[1]&&pos_king[1]<pos_ladya2[1])
           {
                printf("äâå àòàêóþùèå ëàäüè ñïðàâà îò êîðîëÿ\n");


                int max = pos_ladya1[1];
                if (max<pos_ladya3[1])
                   {
                       max = pos_ladya3[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;
           }
           else if (pos_king[1]>pos_ladya2[1]&&pos_king[1]>pos_ladya3[1]&&pos_king[1]<pos_ladya1[1])
           {
                printf("äâå àòàêóþùèå ëàäüè ñâåðõó îò êîðîëÿ\n");
                int max = pos_ladya2[1];
                if (max<pos_ladya3[1])
                   {
                       max = pos_ladya3[1];
                       second_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;
           }

           else if (pos_king[1]<pos_ladya1[1]&&pos_king[1]<pos_ladya2[1]&&pos_king[1]>pos_ladya3[1])
           {
                printf("äâå àòàêóþùèå ëàäüè ñâåðõó îò êîðîëÿ\n");
                int min = pos_ladya1[1];
                if (min>pos_ladya2[1])
                   {
                       min = pos_ladya2[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;
           }

           else if (pos_king[1]<pos_ladya1[1]&&pos_king[1]<pos_ladya3[1]&&pos_king[1]>pos_ladya2[1])
           {
                printf("äâå àòàêóþùèå ëàäüè ñíèçó îò êîðîëÿ\n");
                int min = pos_ladya1[1];
                if (min>pos_ladya3[1])
                   {
                       min = pos_ladya3[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;
           }
           else if (pos_king[1]<pos_ladya2[1]&&pos_king[1]<pos_ladya3[1]&&pos_king[1]>pos_ladya1[1])
           {
                printf("äâå àòàêóþùèå ëàäüè ñíèçó îò êîðîëÿ\n");
                int min = pos_ladya2[1];
                if (min>pos_ladya3[1])
                   {
                       min = pos_ladya3[1];
                       second_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;
           }
       }


       else if (first_ladya_attack_flag==1&&second_ladya_attack_flag==1)
       {
        printf("Äâå ëàäüè ðàñïîëîæåíû íà îäíîé ëèíèè ïî ñòîëáöó áóêâ è ñàìàÿ áëèçêà èç íèõ àòàêóåò êîðîëÿ\n");
           if (pos_king[1]>pos_ladya1[1]&&pos_king[1]>pos_ladya2[1])
           {
                printf("Îáå àòàêóþùèå ëàäüè ñâåðõó îò êîðîëÿ\n");
                int max = pos_ladya1[1];
                if (max<pos_ladya2[1])
                   {
                       max = pos_ladya2[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;


           }

           else if (pos_king[1]<pos_ladya1[1]&&pos_king[1]<pos_ladya2[1])
           {
                printf("Îáå àòàêóþùèå ëàäüè ñíèçó îò êîðîëÿ\n");
                int min = pos_ladya1[1];
                if (min>pos_ladya2[1])
                   {
                       min = pos_ladya2[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;

           }
           else
            printf("äâå àòàêóþùèå ëàäüè ðàñïîëîæåíû ïî îáå ñòîðîíû îò êîðîëÿ\n");
       }

       else if (first_ladya_attack_flag==1&&third_ladya_attack_flag==1)
       {
        printf("Äâå ëàäüè ðàñïîëîæåíû íà îäíîé ëèíèè ïî ñòîëáöó áóêâ è ñàìàÿ áëèçêà èç íèõ àòàêóåò êîðîëÿ\n");
           if (pos_king[1]>pos_ladya1[1]&&pos_king[1]>pos_ladya3[1])
           {
                printf("Îáå àòàêóþùèå ëàäüè ñâåðõó îò êîðîëÿ\n");
                int max = pos_ladya1[1];
                if (max<pos_ladya3[1])
                   {
                       max = pos_ladya3[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;


           }

           else if (pos_king[1]<pos_ladya1[1]&&pos_king[1]<pos_ladya3[1])
           {
                printf("Îáå àòàêóþùèå ëàäüè ñíèçó îò êîðîëÿ\n");
                int min = pos_ladya1[1];
                if (min<pos_ladya3[1])
                   {
                       min = pos_ladya3[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;
           }
           else
            printf("äâå àòàêóþùèå ëàäüè ðàñïîëîæåíû ïî îáå ñòîðîíû îò êîðîëÿ\n");
       }

       else if (second_ladya_attack_flag==1&&third_ladya_attack_flag==1)
       {
        printf("Äâå ëàäüè ðàñïîëîæåíû íà îäíîé ëèíèè ïî ñòîëáöó áóêâ è ñàìàÿ áëèçêà èç íèõ àòàêóåò êîðîëÿ\n");
           if (pos_king[1]>pos_ladya2[1]&&pos_king[1]>pos_ladya3[1])
           {
                printf("Îáå àòàêóþùèå ëàäüè ñâåðõó îò êîðîëÿ\n");
                int max = pos_ladya2[1];
                if (max<pos_ladya3[1])
                   {
                       max = pos_ladya3[1];
                       second_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;


           }

           else if (pos_king[1]>pos_ladya2[1]&&pos_king[1]>pos_ladya3[1])
           {
                printf("Îáå àòàêóþùèå ëàäüè ñíèçó îò êîðîëÿ\n");
                int min = pos_ladya2[1];
                if (min<pos_ladya3[1])
                   {
                       min = pos_ladya3[1];
                       second_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;

           }
           else
            printf("äâå àòàêóþùèå ëàäüè ðàñïîëîæåíû ïî îáå ñòîðîíû îò êîðîëÿ\n");
       }




    if(first_ladya_attack_flag==2)
    {
        printf("Ïåðâàÿ ëàäüÿ, íàõîäÿùàÿñÿ íà ïîçèöèè %s àòàêóå ïî ãîðèçîíòàëè\n", pos_ladya1);
    }
    else if(first_ladya_attack_flag==1)
    {
        printf("Ïåðâàÿ ëàäüÿ, íàõîäÿùàÿñÿ íà ïîçèöèè %s àòàêóå ïî âåðòèêàëè\n", pos_ladya1);
    }
    if(second_ladya_attack_flag==2)
    {
        printf("Âòîðàÿ ëàäüÿ, íàõîäÿùàÿñÿ íà ïîçèöèè %s àòàêóå ïî ãîðèçîíòàëè\n", pos_ladya2);
    }
    else if(second_ladya_attack_flag==1)
    {
        printf("Âòîðàÿ ëàäüÿ, íàõîäÿùàÿñÿ íà ïîçèöèè %s àòàêóå ïî âåðòèêàëè\n", pos_ladya2);
    }
    if(third_ladya_attack_flag==2)
    {
        printf("Òðåòüÿ ëàäüÿ, íàõîäÿùàÿñÿ íà ïîçèöèè %s àòàêóå ïî ãîðèçîíòàëè\n", pos_ladya3);
    }
    else if(third_ladya_attack_flag==1)
    {
        printf("Òðåòüÿ ëàäüÿ, íàõîäÿùàÿñÿ íà ïîçèöèè %s àòàêóå ïî âåðòèêàëè\n", pos_ladya3);
    }


    printf("Hello world!\n");
    return 0;
}
