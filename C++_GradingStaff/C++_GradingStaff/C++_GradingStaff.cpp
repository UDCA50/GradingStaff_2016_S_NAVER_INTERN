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
#include<string>

#define STAFF_NUM_SIZE 99999

int errorHandling_IO(int argc, char** argv){

	int digIter = 0;
	
	//[error 001]
	if (argc < 2){ std::cout << "[error 001] : invaild input\n";  return 0; }
	//[error 002]
	else if (argc >= 3){ std::cout << "[error 002] : invaild input\n"; return 0; }
	
	//[error 003]
	for (digIter = 0; digIter < strlen(argv[1]); digIter++){
		if (isdigit(argv[1][digIter]) == 0) {
			std::cout << "[error 003] :invaild input\n";
			return 0;
		}
	}
	//[error 004]
	if (std::stoi(argv[1], nullptr) <= 0){
		std::cout << "[error 004] :invaild input\n";
		return 0;
	}

	return 1;

}

//make lookupTable ( default value :true)
bool* makeLUT(){
	bool* LUT = new bool[STAFF_NUM_SIZE];
	return LUT;
}
int printHelp(int errorCode){
	//���� �ڵ忡 ���� help�� bold �Ͽ� ���
	return 0;
}




int main(int argc, char** argv){
	if ((errorHandling_IO(argc, argv))){
		bool* LUT = makeLUT();


	}
	return 1;

}