// �����ȣ ������α׷�
// 20160522 �ۼ�

// �Է� : 0�̻� ���� 
// ��� : �����ȣ ����

/* �����϶�
* �����ȣ�� NT�� �ٲܼ� ����
* ���� �ټ��ڸ��� random ����
* random ���� 99999 ���ϸ� 0���� ä�� (30�̶�� NT00030)
* �����ȣ �ߺ� �ȵ�.
* score�� 0���̻� 100�� �̸�
*/

//���� ó�� : ����� ���ڰ� 5�̻��� ��� => 5�� ���� �ٹٲ� ���



//���� ó�� 001 : ���α׷� ����� ���ڰ� �Էµ��� �ʴ°�� => --help ��� ����
//���� ó�� 002 : ���α׷� ����� ���ڰ� 2���̻� ������ ��� =>  --help ��� ����
//���� ó�� 003 : ���α׷� ����� �Է��� ���ڰ� �ƴѰ�� ==> --help ��� ����
//���� ó�� 004 : ���α׷� ����� ���ڰ� 0�̳� ���� ������ �ԷµǴ°�� => --help ��� ����



#include<iostream>
#include<cctype>
#include<cstring>

int errorHandling_IO(int argc, char** argv){

	int digIter = 0;
	int numberLength = strlen(argv[1]);

	if (argc < 2){ std::cout << "[error 001] : invaild input ";  return 0; }
	else if (argc >= 3){ std::cout << "[error 002] : invaild input"; return 0; }
	
	for (digIter = 0; digIter < numberLength; digIter){
		if (isdigit(argv[1][digIter] == 0)) {
			std::cout << "[error 003] :invaild input";
			return 0;
		}
	}

	return 1;

}

int printHelp(int errorCode){
	//���� �ڵ忡 ���� help�� bold �Ͽ� ���
}

int main(int argc, char** argv){
	if ((errorHandling_IO(argc, argv))){
		//making Staff number
	}


	return 1;

}