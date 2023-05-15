#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _sproduct { // 양방향 링크드리스
   int id;
   char name[50];
   int price;
   int quantity;
   struct _sproduct *prev;
   struct _sproduct *next;
} Product, *PProduct;

typedef struct _scustomer { // 양방향 링크드리스
    char name[50];
    char phone[20];
    char email[50];
   struct _scustomer* prev;
   struct _scustomer* next;
} Customer, *PCustomer;

typedef struct _sorder { // 양방향 링크드리스
   int id;
   int orderDate;
   int orderNum;
   struct _sorder* prev;
   struct _sorder* next;
} Order, *POrder;

// 전역변수
Product gProduct = {0,};
Customer gCustomer = {0,};
Order gOrder = {0,};

PProduct addProduct() {
   PProduct p = &gProduct, pAdd;
   while (p->next) p = p->next; // 맨 끝으로 이동
   // 동적 메모리 할당 및 링크드리스트 연결
   pAdd = (PProduct)malloc(sizeof(Product));
   pAdd->prev = p;
   pAdd->next = 0;
   p->next = pAdd;
   return pAdd;
}
PCustomer addCustomer() {
   PCustomer p = &gCustomer, pAdd;
   while (p->next) p = p->next; // 맨 끝으로 이동
   // 동적 메모리 할당 및 링크드리스트 연결
   pAdd = (PCustomer)malloc(sizeof(Customer));
   pAdd->prev = p;
   pAdd->next = 0;
   p->next = pAdd;
   return pAdd;
}
POrder addOrder() {
   POrder p = &gOrder, pAdd;
   while (p->next) p = p->next; // 맨 끝으로 이동
   // 동적 메모리 할당 및 링크드리스트 연결
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
// id로 상품찾기
PProduct findProductById(int id) {
   PProduct p;
   p = gProduct.next;
   while (p) {
      if (p->id == id) return p; // 있다면
      p = p->next;
   }
   printf("상품을 찾을수 없음.\n");
   return 0; // 없다면
}
// name으로 상품 찾기
PProduct findProductByName(char* name) {
   PProduct p;
   p = gProduct.next;
   while (p) {
      if (strcmp(p->name, name) == 0) return p;
      p = p->next;
   }
   printf("상품을 찾을수 없음.\n");
   return 0;
}
// name으로 고객 찾기
PCustomer findCustomerByName(char* name) {
   PCustomer p;
   p = gCustomer.next;
   while (p) {
      if (strcmp(p->name, name) == 0) return p;
      p = p->next;
   }
   printf("고객을 찾을수 없음.\n");
   return 0;
}
// id로 주문찾기
POrder findOrderById(int id) {
   POrder p;
   p = gOrder.next;
   while (p) {
      if (p->id == id) return p; // 있다면
      p = p->next;
   }
   printf("주문을 찾을수 없음.\n");
   return 0; // 없다면
}

// 상품 등록
void AddProduct() {
   PProduct p = addProduct();
   printf("상품 ID 입력: ");
   scanf("%d", &p->id);
   printf("상품명 입력: ");
   scanf("%s", p->name);
   printf("가격 입력: ");
   scanf("%d", &p->price);
   printf("수량 입력: ");
   scanf("%d", &p->quantity);
   printf("상품 추가 완료!\n");
}
// 고객 등록
void AddCustomer() {
   PCustomer p = addCustomer();
   printf("고객이름 입력: : ");
   scanf("%s", p->name);
   printf("고객 연락처 입력: ");
   scanf("%s", p->phone);
   printf("고객 이메일 입력: ");
   scanf("%s", &p->email);
    printf("고객 추가 완료!\n");
}
// 주문 등록
void AddOrder() {
   POrder p = addOrder();
   printf("주문 ID 입력: ");
   scanf("%d", &p->id);
   printf("주문날짜 입력: ");
   scanf("%d", &p->orderDate);
   printf("주문번호 입력: ");
   scanf("%d", &p->orderNum);
}
// 상품 수정
void UpdateProduct() {
   PProduct p;
   int id;
   printf("수정할 상품 id입력: ");
   scanf("%d", &id);

   p = findProductById(id);
   if (p == 0) return;
   printf("상품명 입력: ");
   scanf("%s", p->name);
   printf("상품 가격 입력: ");
   scanf("%d", &p->price);
   printf("수량 입력: ");
   scanf("%d", &p->quantity);
   printf("상품 수정 완료!\n");
}
// 고객 수정
void UpdateCustomer() {
   PCustomer p;
    char name[50];
    printf("수정할 고객 이름 입력: ");
    scanf("%s", name);
   p = findCustomerByName(name);
   if (p == 0) return;
    printf("고객 연락처 입력: ");
    scanf("%s", p->phone);
    printf("고객 이메일 입력: ");
    scanf("%s", p->email);
    printf("고객 수정 완료!\n");
}
// 주문 수정
void UpdateOrder() {
   POrder p;
    int id;
    printf("수정할 주문 ID 입력: ");
    scanf("%d", &id);
   p = findOrderById(id);
   if (p == 0) return;
    printf("주문 날짜 입력: ");
   scanf("%d", &p->orderDate);
   printf("주문번호 입력: ");
   scanf("%d", &p->orderNum);
   printf("주문 수정 완료!\n");
}
// 상품 삭제
void DeleteProduct() {
   PProduct p;
   int id;
   printf("삭제할 상품 id 입력: ");
   scanf("%d", &id);

   p = findProductById(id);
   if (p == 0) return;
   deleteProduct(p);
   printf("상품 삭제 완료!\n");
}
// 고객 삭제
void DeleteCustomer() {
   PCustomer p;
    char name[50];
    printf("삭제할 고객이름 입력: ");
    scanf("%s", name);
   p = findCustomerByName(name);
   if (p == 0) return;
    deleteCustomer(p);
    printf("고객이 삭제되었습니다\n");
}
// 주문 삭제
void DeleteOrder() {
   POrder p;
    int id;
    printf("삭제할 주문 ID 입력: ");
    scanf("%d", &id);
   p = findOrderById(id);
   if (p == 0) return;
    deleteOrder(p);
    printf("주문이 삭제되었었습니다\n");
}
// 상품 출력 (상품 검색)
void PrintProduct() {
   PProduct p;
   char name[50];
   printf("검색할 상품이름 입력: ");
   scanf("%s", name);
   p = findProductByName(name);
   if (p == 0) return; // 상품이 없다면
   printf("ID\tName\tPrice\tQuantity\n");
   printf("%d\t%s\t%d\t%d\n", p->id, p->name, p->price, p->quantity);
}
// 고객 출력(고객 검색)
void PrintCustomer() {
   PCustomer p;
   char name[50];
   printf("검색할 고객이름 입력: ");
   scanf("%s", name);
   p = findCustomerByName(name);
   if (p == 0) return; // 고객이 없다면
   printf("이름\t연락처\t이메일\n");
   printf("%s\t%s\t%s\n", p->name, p->phone, p->email);
}
// 주문 출력(주문 검색)
void PrintOrder() {
   POrder p;
   int id;
   printf("검색할 주문 id 입력: ");
   scanf("%d", &id);
   p = findOrderById(id);
   if (p == 0) return; // 주문이 없다면
   printf("ID\tOrderdate\tOrdernum\n");
    printf("%d\t%d\t%d\n", p->id, p->orderDate, p->orderNum);
}
// 모든 상품 출력
void PrintAllProduct() {
   PProduct p = gProduct.next;
   printf("ID\tName\tPrice\tQuantity\n");
   while (p) {
      printf("%d\t%s\t%d\t%d\n", p->id, p->name, p->price, p->quantity);
      p = p->next;
   }
}
// 모든 고객 출력
void PrintAllCustomer() {
   PCustomer p = gCustomer.next;
   printf("이름\t연락처\t이메일\n");
   while (p) {
      printf("%s\t%s\t%s\n", p->name, p->phone, p->email);
      p = p->next;
   }
}
// 모든 주문 출력
void PrintAllOrder() {
   POrder p = gOrder.next;
   printf("ID\tOrderdate\tOrdernum\n");
   while (p) {
      printf("%d\t%d\t%d\n", p->id, p->orderDate, p->orderNum);
      p = p->next;
   }
}
// 상품 파일 저장
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
// 고객 파일 저장
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
// 주문 파일 저장
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
// 상품 파일 불러오기
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
   // 파일 닫기
   fclose(fp);
   printf("Products loaded successfully!\n");
}
// 고객 파일 불러오기
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
   // 파일 닫기
   fclose(fp);
   printf("Customers loaded successfully!\n");
}
// 주문 파일 불러오기
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
   // 파일 닫기
   fclose(fp);
   printf("Orders loaded successfully!\n");
}
// 메뉴 구현
enum {ADDPRODUCT = 1, UPDATEPRODUCT, DELETEPRODUCT, PRINTPRODUCT, PRINTALLPRODUCT, SAVEPRODUCT, LOADPRODUCT
   , ADDCUSTOMER, UPDATECUSTOMER, DELETECUSTOMER, PRINTCUSTOMER, PRINTALLCUSTOMER, SAVECUSTOMER, LOADCUSTOMER
   , ADDORDER, UPDATEORDER, DELETEORDER, PRINTORDER, PRINTALLORDER, SAVEORDER, LOADORDER
   , EXIT};
void menu() {
    printf("\n===== 상품 관리 시스템 =====\n");
    printf("1. 상품 등록\n");
    printf("2. 상품 수정\n");
    printf("3. 상품 삭제\n");
    printf("4. 상품 출력(검색)\n");
   printf("5. 모든 상품 출력\n");
    printf("6. 상품 저장\n");
    printf("7. 상품 불러오기\n");
    printf("\n===== 고객 관리 시스템 =====\n");
    printf("8. 고객 등록\n");
    printf("9. 고객 수정\n");
    printf("10. 고객 삭제\n");
    printf("11. 고객 출력(검색)\n");
   printf("12. 모든 고객 출력\n");
    printf("13. 고객 저장\n");
    printf("14. 고객 불러오기\n");
    printf("\n===== Order Inventory System =====\n");
    printf("15. 주문 등록\n");
    printf("16. 주문 수정\n");
    printf("17. 주문 삭제\n");
    printf("18. 주문 출력(검색)\n");
   printf("19. 모든 주문 출력\n");
    printf("20. 주문 저장\n");
    printf("21. 주문 불러오기\n");
    printf("22. 프로그램 종료\n");
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
         printf("프로그램을 종료합니다.\n");
         deleteAllProduct();
         deleteAllCustomer();
         deleteAllOrder();
         return 0;
      default:
         printf("잘못된 입력입니다. 다시 입력해주세요.\n");
         break;
      }
   }
    return 0;
}
