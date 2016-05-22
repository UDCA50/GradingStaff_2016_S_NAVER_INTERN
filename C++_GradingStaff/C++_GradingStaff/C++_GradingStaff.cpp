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


//���� ó�� 001 : ���α׷� ����� ���ڰ� �Էµ��� �ʴ°��
//���� ó�� 002 : ���α׷� ����� ���ڰ� 2���̻� ������ ���
//���� ó�� 003 : ���α׷� ����� �Է��� ���ڰ� �ƴѰ��
//���� ó�� 004 : ���α׷� ����� ���ڰ� 0�̳� ���� �����̰ų� �Է��� 99999�� �Ѿ�°��

#include<iostream>
#include<cctype>
#include<string>
#include<vector>
#include<set>
#include<random>
#include<cstdint>
#include<iomanip>

#define STAFF_NUM_SIZE 99999

int errorHandling_Para(int argc, char** argv){

	unsigned int digIter = 0;
	
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
	int inputValue = std::stoi(argv[1], nullptr);
	//[error 004]
	if (inputValue <= 0 && inputValue>10000 ){
		std::cout << "[error 004] :invaild input\n";
		return 0;
	}

	return 1;

}

//make lookupTable 
// �߰������� ������ ������ �ʿ䰡 �ִٸ� => vector �� hashmap ���� ��ȯ
std::vector<int>* makeLUT(){
	std::vector<int>* numberLUT = new std::vector<int>;
	for (int i = 1; i <= STAFF_NUM_SIZE; i++){
		numberLUT->push_back(i);
	}
	return numberLUT;

}


//���� ���� - �޸��� Ʈ������ ����
std::uniform_int_distribution<int>::result_type generateRand(int max){
	//MT19937
	static std::default_random_engine engine{};
	static std::uniform_int_distribution<int> dist{ 1, max};
	return dist(engine);

}

int generateNum(std::vector<int>* numberLUT){
	int i = 0;
	int j = 0;
	int gen_number = 0;
	int returnNumber = 0;
		gen_number = generateRand(numberLUT->size());
		returnNumber = numberLUT->at(gen_number);
		numberLUT->erase(numberLUT->begin() + gen_number);
		return returnNumber;
}
void printNumber(int generateNum){
	std::cout << generateNum << std::endl;
}
int printHelp(int errorCode){
	//���� �ڵ忡 ���� help�� bold �Ͽ� ���
	return 0;
}



int main(int argc, char** argv){
	

	//parameter error handle
	if ((errorHandling_Para(argc, argv))){
	
		//request number
		unsigned int requestNumber = std::stoi(argv[1], nullptr, 10);
		//make LUT
		std::vector<int>* numberLUT = makeLUT();

		//make Number & print Number
		int j = 0;
		for ( j = 0; j < requestNumber; j++){
			std::cout << numberLUT->size() << " ";
			printNumber(generateNum(numberLUT));
		}

	}

	return 1;

}