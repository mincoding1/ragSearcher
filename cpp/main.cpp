#include <iostream>
#include <string>

using namespace std;

//Google에서 제공하는 코드로 변경 불가
class GoogleAPI { 
public:
	std::string run(string context) {
		// (생략) API 호출 후 반환 소스코드...
		return "google data...";
	}
};

//Bing에서 제공하는 코드로 변경 불가
class BingAPI {
public:
	std::string go(string context) {
		// (생략) API 호출 후 반환 소스코드...
		return "bing data...";
	}
};

//Yahoo에서 제공하는 코드로 변경 불가
class YahooAPI {
public:
	std::string api(string context) {
		// (생략) API 호출 후 반환 소스코드...
		return "yahoo data...";
	}
};

//추론 Library이며 코드 변경 불가
class Inferencer {
public:
	string inference(string modelName, string context) {
		// (생략)모델 추론
		return "OH! Long time no see!";
	}
};

int main() {

	int hangle; //0 : 한글, 1 : 영어

	string origin_input;
	int origin_cnt;

	cout << "무엇이든지 물어보세요 : ";
	char buf[256];
	cin.getline(buf, 255);
	string line(buf);

	int price = 0;

	int flag = 0;
	int cnt = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] > 127 || line[i] < 0) {
			flag = 1;
		}

		if (line[i] == ' ') continue;
		cnt++;
	}

	origin_input = line;


	origin_cnt = cnt;

	if (flag == 1) hangle = 0;
	else hangle = 1;

	cout << "\n사용할 검색엔진의 번호를 입력하세요.\n";
	cout << "1. Google\n";
	cout << "2. Bing\n";
	cout << "3. Yahoo\n";

	cout << "================\n입력 : ";
	int input1;
	cin >> input1;
	cout << "\n";

	if (input1 == 1) price += (30 * origin_cnt);
	else if (input1 == 2) price += (20 * origin_cnt);
	else if (input1 == 3) price += (15 * origin_cnt);

	if (input1 == 1) {
		if (origin_cnt < 10) {
			price = 50 * origin_cnt;
		}
	}
	else if (input1 == 2) {
		if (origin_cnt <= 30) {
			price /= 2;
		}
	}

	//2. 검색엔진 API
	GoogleAPI t1;
	BingAPI t2;
	YahooAPI t3;

	string r1 = t1.run(origin_input);
	string r2 = t2.go(origin_input);
	string r3 = t3.api(origin_input);

	string result = "";
	if (input1 == 1) result = r1;
	else if (input1 == 2) result = r2;
	else if (input1 == 3) result = r3;

	cout << "사용할 모델의 번호를 입력하세요.\n";

	if (hangle == 0) {
		cout << "1. GPT\n";
		cout << "2. Gemini\n";
		cout << "3. Llama\n";
	}
	else {
		cout << "1. Llama\n";
	}
	cout << "================\n입력 : ";

	int input;
	cin >> input;
	cout << "\n";

	cnt = origin_cnt;
	if (hangle == 0) {
		if (input == 1) {
			if (cnt > 20) {
				price += 1000;
				price += (cnt * 50);
			}
			else {
				price += 1000;
				price += (cnt * 100);
			}
		}
		if (input == 2) {
			if (cnt >= 100) {
				price += 100;
				price += (cnt * 120);
			}
			else {
				price += 100;
				price += (cnt * 150);
			}
		}

		if (input == 3) {
			price += cnt * 130;
		}
	}
	else {
		if (input == 1) {
			price += cnt * 90;
		}
	}

	Inferencer model;

	//관련 검색어와 함께 모델에 추론시키기
	string result2;
	if (hangle == 0 && input == 1) {
		result2 = model.inference("GPT", result + " " + line);
	}
	else if (hangle == 0 && input == 2) {
		result2 = model.inference("Gemini", result + " " + line);
	}

	else if (hangle == 0 && input == 3) {
		result2 = model.inference("Llama", result + " " + line);
	}


	else if (hangle == 1 && input == 1) {
		result2 = model.inference("Llama", result + " " + line);
	}
	else {
		std::cout << "ERROR :: 유효하지 않은 입력입니다.\n";
		return 0;
	}

	if (input1 < 1 || input1 > 3) {
		std::cout << "ERROR :: 존재하지 않는 검색엔진입니다.\n";
		return 0;
	}

	cout << "추론결과\n==============================\n";
	cout << result2 << "\n";
	cout << "Total Price : " << price << "\n";

	return 0;
}
