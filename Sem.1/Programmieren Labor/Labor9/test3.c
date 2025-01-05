#include <stdio.h>
#include <string.h>

typedef struct Student
{
    char nachname[20];
    char vorname[20];
    char studiengang[20];
    int matrikelnummer;
    struct student *next;

} Student;

int creatRoot(int data)
{

    struct Student *newNode = (struct Student *)malloc(sizeof(struct Student));
    if (newNode == NULL)
    {
        printf("Speicher konnte nicht zugewiesen werden.\n");
        return NULL;
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int append()
{
}

int printList()
{
}

int main(int argc, char *argv[])
{
}