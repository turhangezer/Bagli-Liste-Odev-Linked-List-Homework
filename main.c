#include <stdio.h>
#include <stdlib.h>


typedef struct n
{
    char no[20],ad[20],soyad[20],sinif[20],bolum[40];
    struct n* next;
    struct n* prev;
} node;
typedef struct
{
    node* root;

} List;

List* sil(List* l)
{
    if(l==NULL)
    {
        printf("liste yok\n\n\n\n");
        return l;
    }
    if(l->root==NULL)
    {
        printf("listede ogrenci yok\n\n\n\n\n");
        return l;
    }
    printf("silmek istediginiz ogrencinin numarasini giriniz: ");
    char numara[20];
    scanf("%s",numara);
    node* iter=l->root;
    while(iter!=NULL)
    {

        if(strcmp(iter->no,numara)==0)
        {
            //eger dugum aradaysa
            if(iter->prev!=NULL && iter->next!=NULL)
            {
                iter->prev->next=iter->next;
                iter->next->prev=iter->prev;
                free(iter);
                printf("Ogrenci Silindi\n\n\n\n\n");
                return l;
            }
            //eger dugum bastaysa
            else if(iter->prev==NULL)
            {
                if(iter->next!=NULL) //liste tek elemanli mi diye bakiyoruz
                {
                    iter->next->prev=NULL;
                    l->root=iter->next;
                    free(iter);
                    printf("Ogrenci Silindi\n\n\n\n\n");
                    return l;
                }
                else
                    l->root=NULL;
                printf("Ogrenci Silindi\n\n\n\n\n");
                return l;

            }
            else//eger son elemansa
            {
                iter->prev->next=NULL;
                free(iter);
                printf("Ogrenci Silindi\n\n\n\n\n");
                return l;
            }

            break;
        }
        iter=iter->next;
        if(iter==NULL)
        {
            printf("silmek istediginiz ogrenci bulunmamaktadir\n\n\n\n");
            return l;
        }
    }

}

void bul(List* l)
{
    if(l==NULL)
    {
        printf("liste yok\n\n\n\n\n");
        return 0;
    }
    if(l->root==NULL)
    {
        printf("listede ogrenci yok\n\n\n\n\n");
        return l;
    }
    printf("aradiginiz ogrencinin numarasini giriniz");
    char numara[20];
    scanf("%s",numara);
    node* iter=l->root;
    while(iter!=NULL)
    {
        if(strcmp(iter->no,numara)==0)
        {
            printf("numarasi girilen ogrencinin;\nAdi:%s\nSoyadi:%s\nsinifi:%s\nbolumu:%s\n\n\n\n\n",iter->ad,iter->soyad,iter->sinif,iter->bolum);
            break;
        }
        iter=iter->next;
    }
    if(iter==NULL)
    {
        printf("aradiginiz ogrenci bulunamadi\n\n\n\n\n");
    }
}

List* olustur(List* l)
{
    if(l!=NULL)
    {
        printf("Liste Zaten Var\n\n\n\n\n");
        return l;
    }
    l=(List*)malloc(sizeof(List));
    l->root=NULL;
    printf("Liste Olusturuldu\n\n\n\n\n");
    return l;

}
void ekle(List* list)
{

    if(list==NULL)
    {
        printf("liste yok\n\n\n\n\n");
        return 0;
    }
    node* temp=(node*)malloc(sizeof(node));
    printf("ogrencinin numarasi: ");
    scanf("%s",temp->no);
    printf("ogrencinin adi: ");
    scanf("%s",temp->ad);
    printf("ogrencinin soyadi: ");
    scanf("%s",temp->soyad);
    printf("ogrencinin sinifi: ");
    scanf("%s",temp->sinif);
    printf("ogrencinin bolumu: ");
    scanf("%s",temp->bolum);

    node* iter=list->root;
    if(iter!=NULL)
    {
        if(strcmp(temp->no,iter->no)==0)
        {
            printf("Bu numaraya sahip bir ogrenci zaten var!\n\n\n\n");
            return 1;
        }
        while(iter->next!=NULL)
        {

            iter=iter->next;
            if(strcmp(temp->no,iter->no)==0)
            {
                printf("Bu numaraya sahip bir ogrenci zaten var!");
                return 1;
            }
        }
        iter->next=temp;
        temp->prev=iter;
        temp->next=NULL;
        printf("ogrenci listeye eklendi\n\n\n\n\n");

    }
    else
    {
        list->root=(node*)malloc(sizeof(node));
        list->root=temp;
        temp->prev=NULL;
        temp->next=NULL;
        printf("ogrenci listeye eklendi\n");

    }
}
void bastir(List* l)
{
    if(l==NULL)
    {
        printf("Liste yok\n\n\n\n\n");
        return 0;
    }
    if(l->root==NULL)
    {
        printf("listede ogrenci yok\n\n\n\n\n");
        return 0;
    }
    node* iter=l->root;
    while(iter!=NULL)
    {
        printf("ogrencinin numarasi:%s\n ogrencinin adi: %s\n ogrencinin soyadi: %s\n ogrencinin sinifi: %s\nogrencinin bolumu: %s\n\n\n",iter->no,iter->ad,iter->soyad,iter->sinif,iter->bolum);
        iter=iter->next;
    }
}

node* listeyisil(List* l)
{
    if(l==NULL)
    {
        printf("Liste yok\n\n\n\n\n");
        return l;
    }
    node* iter=l->root;
    while(iter!=NULL)
    {
        node* temp=iter;
        iter=iter->next;
        free(temp);
    }
    free(iter);
    free(l);
    printf("liste silindi\n\n\n\n\n");
    return NULL;
}
int main()
{
    List* list=NULL;

    while(1)
    {
        printf("yapmak istediginiz islemi seciniz:\n1-Liste Olustur\n2-Listeyi Goster\n3-Listeyi Sil\n4-Listeye Yeni ogrenci ekle\n5-Ogrenci Sil\n6-bir ogrenciyi bul\n7-cikis\n" );
        int x;
        scanf("%d",&x);
        if(x<=0 || x>7){
            printf("Gecersiz bir numara girdiniz!!");
            exit(0);
        }
        switch(x)
        {
        case 1:
            list=olustur(list);
            break;
        case 2:
            bastir(list);
            break;
        case 3:
            list=listeyisil(list);
            break;
        case 4:
            ekle(list);
            break;
        case 5:
            list=sil(list);
            break;
        case 6:
            bul(list);
            break;
        case 7:
            exit(0);
            break;

        }
    }

    return 0;
}
