#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _sproduct { // ����� ��ũ�帮��
   int id;
   char name[50];
   int price;
   int quantity;
   struct _sproduct *prev;
   struct _sproduct *next;
} Product, *PProduct;

typedef struct _scustomer { // ����� ��ũ�帮��
    char name[50];
    char phone[20];
    char email[50];
   struct _scustomer* prev;
   struct _scustomer* next;
} Customer, *PCustomer;

typedef struct _sorder { // ����� ��ũ�帮��
   int id;
   int orderDate;
   int orderNum;
   struct _sorder* prev;
   struct _sorder* next;
} Order, *POrder;

// ��������
Product gProduct = {0,};
Customer gCustomer = {0,};
Order gOrder = {0,};

PProduct addProduct() {
   PProduct p = &gProduct, pAdd;
   while (p->next) p = p->next; // �� ������ �̵�
   // ���� �޸� �Ҵ� �� ��ũ�帮��Ʈ ����
   pAdd = (PProduct)malloc(sizeof(Product));
   pAdd->prev = p;
   pAdd->next = 0;
   p->next = pAdd;
   return pAdd;
}
PCustomer addCustomer() {
   PCustomer p = &gCustomer, pAdd;
   while (p->next) p = p->next; // �� ������ �̵�
   // ���� �޸� �Ҵ� �� ��ũ�帮��Ʈ ����
   pAdd = (PCustomer)malloc(sizeof(Customer));
   pAdd->prev = p;
   pAdd->next = 0;
   p->next = pAdd;
   return pAdd;
}
POrder addOrder() {
   POrder p = &gOrder, pAdd;
   while (p->next) p = p->next; // �� ������ �̵�
   // ���� �޸� �Ҵ� �� ��ũ�帮��Ʈ ����
   pAdd = (POrder)malloc(sizeof(Order));
   pAdd->prev = p;
   pAdd->next = 0;
   p->next = pAdd;
   return pAdd;
}
void deleteProduct(PProduct del) {
   PProduct prev, next;
   prev = del->prev;
   next = del->next;
   prev->next = next;
   if (next) next->prev = prev;
   free(del);
}
void deleteCustomer(PCustomer del) {
   PCustomer prev, next;
   prev = del->prev;
   next = del->next;
   prev->next = next;
   if (next) next->prev = prev;
   free(del);
}
void deleteOrder(POrder del) {
   POrder prev, next;
   prev = del->prev;
   next = del->next;
   prev->next = next;
   if (next) next->prev = prev;
   free(del);
}
void deleteAllProduct() {
   PProduct p, del;
   p = gProduct.next;
   while (p) {
      del = p;
      p = p->next;
      free(del);
   }
   gProduct.next = 0;
}
void deleteAllCustomer() {
   PCustomer p, del;
   p = gCustomer.next;
   while (p) {
      del = p;
      p = p->next;
      free(del);
   }
   gCustomer.next = 0;
}
void deleteAllOrder() {
   POrder p, del;
   p = gOrder.next;
   while (p) {
      del = p;
      p = p->next;
      free(del);
   }
   gOrder.next = 0;
}
// id�� ��ǰã��
PProduct findProductById(int id) {
   PProduct p;
   p = gProduct.next;
   while (p) {
      if (p->id == id) return p; // �ִٸ�
      p = p->next;
   }
   printf("��ǰ�� ã���� ����.\n");
   return 0; // ���ٸ�
}
// name���� ��ǰ ã��
PProduct findProductByName(char* name) {
   PProduct p;
   p = gProduct.next;
   while (p) {
      if (strcmp(p->name, name) == 0) return p;
      p = p->next;
   }
   printf("��ǰ�� ã���� ����.\n");
   return 0;
}
// name���� �� ã��
PCustomer findCustomerByName(char* name) {
   PCustomer p;
   p = gCustomer.next;
   while (p) {
      if (strcmp(p->name, name) == 0) return p;
      p = p->next;
   }
   printf("���� ã���� ����.\n");
   return 0;
}
// id�� �ֹ�ã��
POrder findOrderById(int id) {
   POrder p;
   p = gOrder.next;
   while (p) {
      if (p->id == id) return p; // �ִٸ�
      p = p->next;
   }
   printf("�ֹ��� ã���� ����.\n");
   return 0; // ���ٸ�
}

// ��ǰ ���
void AddProduct() {
   PProduct p = addProduct();
   printf("��ǰ ID �Է�: ");
   scanf("%d", &p->id);
   printf("��ǰ�� �Է�: ");
   scanf("%s", p->name);
   printf("���� �Է�: ");
   scanf("%d", &p->price);
   printf("���� �Է�: ");
   scanf("%d", &p->quantity);
   printf("��ǰ �߰� �Ϸ�!\n");
}
// �� ���
void AddCustomer() {
   PCustomer p = addCustomer();
   printf("���̸� �Է�: : ");
   scanf("%s", p->name);
   printf("�� ����ó �Է�: ");
   scanf("%s", p->phone);
   printf("�� �̸��� �Է�: ");
   scanf("%s", &p->email);
    printf("�� �߰� �Ϸ�!\n");
}
// �ֹ� ���
void AddOrder() {
   POrder p = addOrder();
   printf("�ֹ� ID �Է�: ");
   scanf("%d", &p->id);
   printf("�ֹ���¥ �Է�: ");
   scanf("%d", &p->orderDate);
   printf("�ֹ���ȣ �Է�: ");
   scanf("%d", &p->orderNum);
}
// ��ǰ ����
void UpdateProduct() {
   PProduct p;
   int id;
   printf("������ ��ǰ id�Է�: ");
   scanf("%d", &id);

   p = findProductById(id);
   if (p == 0) return;
   printf("��ǰ�� �Է�: ");
   scanf("%s", p->name);
   printf("��ǰ ���� �Է�: ");
   scanf("%d", &p->price);
   printf("���� �Է�: ");
   scanf("%d", &p->quantity);
   printf("��ǰ ���� �Ϸ�!\n");
}
// �� ����
void UpdateCustomer() {
   PCustomer p;
    char name[50];
    printf("������ �� �̸� �Է�: ");
    scanf("%s", name);
   p = findCustomerByName(name);
   if (p == 0) return;
    printf("�� ����ó �Է�: ");
    scanf("%s", p->phone);
    printf("�� �̸��� �Է�: ");
    scanf("%s", p->email);
    printf("�� ���� �Ϸ�!\n");
}
// �ֹ� ����
void UpdateOrder() {
   POrder p;
    int id;
    printf("������ �ֹ� ID �Է�: ");
    scanf("%d", &id);
   p = findOrderById(id);
   if (p == 0) return;
    printf("�ֹ� ��¥ �Է�: ");
   scanf("%d", &p->orderDate);
   printf("�ֹ���ȣ �Է�: ");
   scanf("%d", &p->orderNum);
   printf("�ֹ� ���� �Ϸ�!\n");
}
// ��ǰ ����
void DeleteProduct() {
   PProduct p;
   int id;
   printf("������ ��ǰ id �Է�: ");
   scanf("%d", &id);

   p = findProductById(id);
   if (p == 0) return;
   deleteProduct(p);
   printf("��ǰ ���� �Ϸ�!\n");
}
// �� ����
void DeleteCustomer() {
   PCustomer p;
    char name[50];
    printf("������ ���̸� �Է�: ");
    scanf("%s", name);
   p = findCustomerByName(name);
   if (p == 0) return;
    deleteCustomer(p);
    printf("���� �����Ǿ����ϴ�\n");
}
// �ֹ� ����
void DeleteOrder() {
   POrder p;
    int id;
    printf("������ �ֹ� ID �Է�: ");
    scanf("%d", &id);
   p = findOrderById(id);
   if (p == 0) return;
    deleteOrder(p);
    printf("�ֹ��� �����Ǿ������ϴ�\n");
}
// ��ǰ ��� (��ǰ �˻�)
void PrintProduct() {
   PProduct p;
   char name[50];
   printf("�˻��� ��ǰ�̸� �Է�: ");
   scanf("%s", name);
   p = findProductByName(name);
   if (p == 0) return; // ��ǰ�� ���ٸ�
   printf("ID\tName\tPrice\tQuantity\n");
   printf("%d\t%s\t%d\t%d\n", p->id, p->name, p->price, p->quantity);
}
// �� ���(�� �˻�)
void PrintCustomer() {
   PCustomer p;
   char name[50];
   printf("�˻��� ���̸� �Է�: ");
   scanf("%s", name);
   p = findCustomerByName(name);
   if (p == 0) return; // ���� ���ٸ�
   printf("�̸�\t����ó\t�̸���\n");
   printf("%s\t%s\t%s\n", p->name, p->phone, p->email);
}
// �ֹ� ���(�ֹ� �˻�)
void PrintOrder() {
   POrder p;
   int id;
   printf("�˻��� �ֹ� id �Է�: ");
   scanf("%d", &id);
   p = findOrderById(id);
   if (p == 0) return; // �ֹ��� ���ٸ�
   printf("ID\tOrderdate\tOrdernum\n");
    printf("%d\t%d\t%d\n", p->id, p->orderDate, p->orderNum);
}
// ��� ��ǰ ���
void PrintAllProduct() {
   PProduct p = gProduct.next;
   printf("ID\tName\tPrice\tQuantity\n");
   while (p) {
      printf("%d\t%s\t%d\t%d\n", p->id, p->name, p->price, p->quantity);
      p = p->next;
   }
}
// ��� �� ���
void PrintAllCustomer() {
   PCustomer p = gCustomer.next;
   printf("�̸�\t����ó\t�̸���\n");
   while (p) {
      printf("%s\t%s\t%s\n", p->name, p->phone, p->email);
      p = p->next;
   }
}
// ��� �ֹ� ���
void PrintAllOrder() {
   POrder p = gOrder.next;
   printf("ID\tOrderdate\tOrdernum\n");
   while (p) {
      printf("%d\t%d\t%d\n", p->id, p->orderDate, p->orderNum);
      p = p->next;
   }
}
// ��ǰ ���� ����
void SaveProduct() {
   PProduct p = gProduct.next;
   FILE* fp;
   fp = fopen("products.txt", "w");
   if (fp == NULL) {
      printf("Error opening file.\n");
      return;
   }
   while (p) {
      fprintf(fp, "%d\t%s\t%d\t%d\n", p->id, p->name, p->price, p->quantity);
      p = p->next;
   }
   fclose(fp);
   printf("Products saved successfully!\n");
}
// �� ���� ����
void SaveCustomer() {
   PCustomer p = gCustomer.next;
   FILE* fp;
   fp = fopen("customers.txt", "w");
   if (fp == NULL) {
      printf("Error opening file.\n");
      return;
   }
   while (p) {
      fprintf(fp, "%s\t%s\t%s\n", p->name, p->phone, p->email);
      p = p->next;
   }
   fclose(fp);
   printf("Customers saved successfully!\n");
}
// �ֹ� ���� ����
void SaveOrder() {
   POrder p = gOrder.next;
   FILE* fp;
   fp = fopen("orders.txt", "w");
   if (fp == NULL) {
      printf("Error opening file.\n");
      return;
   }
   while (p) {
      fprintf(fp, "%d\t%d\t%d\n", p->id, p->orderDate, p->orderNum);
      p = p->next;
   }
   fclose(fp);
   printf("Orders saved successfully!\n");
}
// ��ǰ ���� �ҷ�����
void LoadProduct() {
   PProduct p;
   FILE* fp;
   int id;
   char name[50];
   int price;
   int quantity; 
   deleteAllProduct();
   fp = fopen("products.txt", "r");
   if (fp == NULL) {
      printf("Error opening file.\n");
      return;
   }
   while (fscanf(fp, "%d\t%s\t%d\t%d\n", &id, name, &price, &quantity) != EOF) {
      p = addProduct();
      p->id = id;
      strcpy(p->name, name);
      p->price = price;
      p->quantity = quantity;
   }
   // ���� �ݱ�
   fclose(fp);
   printf("Products loaded successfully!\n");
}
// �� ���� �ҷ�����
void LoadCustomer() {
   PCustomer p;
   FILE* fp;
   char name[50];
   char phone[20];
   char email[50];
   deleteAllCustomer();
   fp = fopen("customers.txt", "r");
   if (fp == NULL) {
      printf("Error opening file.\n");
      return;
   }
   while (fscanf(fp, "%s\t%s\t%s\n", name, phone, email) != EOF) {
      p = addCustomer();
      strcpy(p->name, name);
      strcpy(p->phone, phone);
      strcpy(p->email, email);
   }
   // ���� �ݱ�
   fclose(fp);
   printf("Customers loaded successfully!\n");
}
// �ֹ� ���� �ҷ�����
void LoadOrder() {
   POrder p;
   FILE* fp;
   int id;
   int orderDate;
   int orderNum;
   deleteAllOrder();
   fp = fopen("orders.txt", "r");
   if (fp == NULL) {
      printf("Error opening file.\n");
      return;
   }
   while (fscanf(fp, "%d\t%d\t%d\n", &id, &orderDate, &orderNum) != EOF) {
      p = addOrder();
      p->id = id;
      p->orderDate = orderDate;
      p->orderNum = orderNum;
   }
   // ���� �ݱ�
   fclose(fp);
   printf("Orders loaded successfully!\n");
}
// �޴� ����
enum {ADDPRODUCT = 1, UPDATEPRODUCT, DELETEPRODUCT, PRINTPRODUCT, PRINTALLPRODUCT, SAVEPRODUCT, LOADPRODUCT
   , ADDCUSTOMER, UPDATECUSTOMER, DELETECUSTOMER, PRINTCUSTOMER, PRINTALLCUSTOMER, SAVECUSTOMER, LOADCUSTOMER
   , ADDORDER, UPDATEORDER, DELETEORDER, PRINTORDER, PRINTALLORDER, SAVEORDER, LOADORDER
   , EXIT};
void menu() {
    printf("\n===== ��ǰ ���� �ý��� =====\n");
    printf("1. ��ǰ ���\n");
    printf("2. ��ǰ ����\n");
    printf("3. ��ǰ ����\n");
    printf("4. ��ǰ ���(�˻�)\n");
   printf("5. ��� ��ǰ ���\n");
    printf("6. ��ǰ ����\n");
    printf("7. ��ǰ �ҷ�����\n");
    printf("\n===== �� ���� �ý��� =====\n");
    printf("8. �� ���\n");
    printf("9. �� ����\n");
    printf("10. �� ����\n");
    printf("11. �� ���(�˻�)\n");
   printf("12. ��� �� ���\n");
    printf("13. �� ����\n");
    printf("14. �� �ҷ�����\n");
    printf("\n===== Order Inventory System =====\n");
    printf("15. �ֹ� ���\n");
    printf("16. �ֹ� ����\n");
    printf("17. �ֹ� ����\n");
    printf("18. �ֹ� ���(�˻�)\n");
   printf("19. ��� �ֹ� ���\n");
    printf("20. �ֹ� ����\n");
    printf("21. �ֹ� �ҷ�����\n");
    printf("22. ���α׷� ����\n");
    printf("Enter your choice (1-22): ");
}

int main() {
    int choice1, choice2;
   while (1) {
      menu();
      scanf("%d", &choice1);
      switch (choice1) {
      case ADDPRODUCT: AddProduct(); break;
      case UPDATEPRODUCT: UpdateProduct(); break;
      case DELETEPRODUCT: DeleteProduct(); break;
      case PRINTPRODUCT: PrintProduct(); break;
      case PRINTALLPRODUCT: PrintAllProduct(); break;
      case SAVEPRODUCT: SaveProduct(); break;
      case LOADPRODUCT: LoadProduct(); break;

      case ADDCUSTOMER: AddCustomer(); break;
      case UPDATECUSTOMER: UpdateCustomer(); break;
      case DELETECUSTOMER: DeleteCustomer(); break;
      case PRINTCUSTOMER: PrintCustomer(); break;
      case PRINTALLCUSTOMER: PrintAllCustomer(); break;
      case SAVECUSTOMER: SaveCustomer(); break;
      case LOADCUSTOMER: LoadCustomer(); break;

      case ADDORDER: AddOrder(); break;
      case UPDATEORDER: UpdateOrder(); break;
      case DELETEORDER: DeleteOrder(); break;
      case PRINTORDER: PrintOrder(); break;
      case PRINTALLORDER: PrintAllOrder(); break;
      case SAVEORDER: SaveOrder(); break;
      case LOADORDER: LoadOrder(); break;

      case EXIT:
         printf("���α׷��� �����մϴ�.\n");
         deleteAllProduct();
         deleteAllCustomer();
         deleteAllOrder();
         return 0;
      default:
         printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
         break;
      }
   }
    return 0;
}
