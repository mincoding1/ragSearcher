#Google에서 제공하는 코드로 변경 불가
class GoogleAPI: 
    def run(self, context: str) -> str:
        # (생략) API 호출 후 반환 소스코드...
        return "google data..."


#Bing에서 제공하는 코드로 변경 불가
class BingAPI:
    def go(self, context: str) -> str:
        # (생략) API 호출 후 반환 소스코드...
        return "bing data..."


#Yahoo에서 제공하는 코드로 변경 불가
class YahooAPI:
    def api(self, context: str) -> str:
        # (생략) API 호출 후 반환 소스코드...
        return "yahoo data..."


#추론 Library이며 코드 변경 불가
class Inferencer:
    def inference(self, modelName: str, context: str) -> str:
        # (생략)모델 추론
        return "OH! Long time no see!"


def main():
    #0 : 한글, 1 : 영어
    hangle = 0  

    origin_input = ""
    origin_cnt = 0

    line = input("무엇이든지 물어보세요 : ")

    price = 0
    flag = 0
    cnt = 0
    for ch in line:
        if ord(ch) > 127 or ord(ch) < 0:
            flag = 1

        if ch == ' ':
            continue
        cnt += 1

    origin_input = line
    origin_cnt = cnt

    if flag == 1:
        hangle = 0
    else:
        hangle = 1

    print("\n사용할 검색엔진의 번호를 입력하세요.")
    print("1. Google")
    print("2. Bing")
    print("3. Yahoo")

    input1 = int(input("================\n입력 : "))
    print()

    if input1 == 1:
        price += (30 * origin_cnt)
    elif input1 == 2:
        price += (20 * origin_cnt)
    elif input1 == 3:
        price += (15 * origin_cnt)

    if input1 == 1:
        if origin_cnt < 10:
            price = 50 * origin_cnt
    elif input1 == 2:
        if origin_cnt <= 30:
            price //= 2

    #2. 검색엔진 API
    t1 = GoogleAPI()
    t2 = BingAPI()
    t3 = YahooAPI()

    r1 = t1.run(origin_input)
    r2 = t2.go(origin_input)
    r3 = t3.api(origin_input)

    result = ""
    if input1 == 1:
        result = r1
    elif input1 == 2:
        result = r2
    elif input1 == 3:
        result = r3

    print("사용할 모델의 번호를 입력하세요.")

    if hangle == 0:
        print("1. GPT")
        print("2. Gemini")
        print("3. Llama")
    else:
        print("1. Llama")

    input_model = int(input("================\n입력 : "))
    print()

    cnt = origin_cnt
    if hangle == 0:
        if input_model == 1:
            if cnt > 20:
                price += 1000
                price += (cnt * 50)
            else:
                price += 1000
                price += (cnt * 100)
        if input_model == 2:
            if cnt >= 100:
                price += 100
                price += (cnt * 120)
            else:
                price += 100
                price += (cnt * 150)
        if input_model == 3:
            price += cnt * 130
    else:
        if input_model == 1:
            price += cnt * 90

    model = Inferencer()

    #관련 검색어와 함께 모델에 추론시키기
    if hangle == 0 and input_model == 1:
        result2 = model.inference("GPT", result + " " + line)
    elif hangle == 0 and input_model == 2:
        result2 = model.inference("Gemini", result + " " + line)
    elif hangle == 0 and input_model == 3:
        result2 = model.inference("Llama", result + " " + line)
    elif hangle == 1 and input_model == 1:
        result2 = model.inference("Llama", result + " " + line)
    else:
        print("ERROR :: 유효하지 않은 입력입니다.")
        return

    if input1 < 1 or input1 > 3:
        print("ERROR :: 존재하지 않는 검색엔진입니다.")
        return

    print("추론결과\n==============================")
    print(result2)
    print("Total Price : " + str(price))


if __name__ == "__main__":
    main()
