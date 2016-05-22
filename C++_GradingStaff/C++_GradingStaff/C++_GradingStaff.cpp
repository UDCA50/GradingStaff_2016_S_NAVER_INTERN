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
//���� ó�� 004 : ���α׷� ����� ���ڰ� 0�̳� ���� �����̰ų� �Է��� 999999�� �Ѿ�°��

#include<iostream>
#include<cctype>
#include<string>
#include<vector>
#include<random>
#include<cstdint>


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
	if (inputValue <= 0 && inputValue>100000 ){
		std::cout << "[error 004] :invaild input\n";
		return 0;
	}

	return 1;

}

//make lookupTable 
// �߰������� ������ ������ �ʿ䰡 �ִٸ� => vector �� hashmap ���� ��ȯ
std::vector<int>* makeLUT(){
	std::vector<int>* numberLUT = new std::vector<int>;
	for (int i = 0; i <= STAFF_NUM_SIZE; i++){
		numberLUT->push_back(i);
	}
	return numberLUT;

}


//���� ���� - �޸��� Ʈ������ ����
std::uniform_int_distribution<int>::result_type generateRand(int max){
	//MT19937
	static std::mersenne_twister_engine<std::uint_fast32_t, 32, 624, 397, 31,
		0x9908b0df, 11,
		0xffffffff, 7,
		0x9d2c5680, 15,
		0xefc60000, 18, 1812433253> engine{};
	static std::uniform_int_distribution<int> dist{ 0, max};
	return dist(engine);

}

int generateNum(unsigned int requestNumber, std::vector<int>* numberLUT){
	int i = 0;
	for (i = 0; i < requestNumber; i++){
		int gen_number = generateRand(numberLUT->size());
		std::cout << numberLUT->at(gen_number) << std::endl;
		numberLUT->erase(numberLUT->begin() + gen_number-1);
	}
	return 1;
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
		generateNum(requestNumber, numberLUT);

	}

	return 1;

}