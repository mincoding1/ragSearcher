# -*- coding: utf-8 -*-

class LycosCralwer:
    def run(self):
        return "lycos data..."

class YahooCralwer:
    def run(self):
        return "yahoo data..."

class GoogleAPI:
    def api(self):
        return "google data..."

class DBConnector:
    def dbInit(self):
        pass

    def saveQuery(self, site, data):
        pass

    def loadQuery(self, context):
        return "result"

    def dbDisconnect(self):
        pass

class Inferencer:
    def inference(self, modelName, context):
        return "OH! Long time no see!"

def main():
    print("무엇이든지 물어보세요 : ", end="")
    line = input()

    price = 0
    flag = 0
    cnt = 0
    for ch in line:
        if ord(ch) > 127:
            flag = 1
        if ch == ' ':
            continue
        cnt += 1

    price = cnt * 100
    hangle = 0 if flag == 1 else 1  # 0 : 한글, 1 : 영어

    print("\n사용할 검색엔진의 번호를 입력하세요.")
    print("1. Lycos")
    print("2. Yahoo")
    print("3. Google")
    print("================\n입력 : ", end="")
    try:
        input1 = int(input().strip())
    except Exception:
        input1 = -1
    print()

    if input1 == 1:
        price += 1000
    elif input1 == 2:
        price += 1000
    elif input1 == 3:
        price += 300

    # 1. 크롤링 엔진
    t1 = LycosCralwer()
    t2 = YahooCralwer()

    # 2. API 엔진
    t3 = GoogleAPI()

    r1 = t1.run()
    r2 = t2.run()
    r3 = t3.api()

    result = ""
    if input1 == 1:
        result = r1
    elif input1 == 2:
        result = r2
    elif input1 == 3:
        result = r3

    db = DBConnector()
    db.dbInit()

    if input1 == 1:
        db.saveQuery("Lycos", r1)
    elif input1 == 2:
        db.saveQuery("Yahoo", r2)
    elif input1 == 3:
        db.saveQuery("Google", r3)

    db.dbDisconnect()

    print("사용할 모델의 번호를 입력하세요.")
    if hangle == 0:
        print("1. GPT")
        print("2. Gemini")
        print("3. Llama")
    else:
        print("1. Llama")
    print("================\n입력 : ", end="")
    try:
        input_model = int(input().strip())
    except Exception:
        input_model = -1
    print()

    if hangle == 0:
        if input_model == 1: price += 500
        if input_model == 2: price += 400
        if input_model == 3: price += 100
    else:
        if input_model == 1: price += 100

    model = Inferencer()

    # DB에서 관련 검색어 가져오기
    db1 = db.loadQuery(line)

    # 관련 검색어와 함께 모델에 추론시키기
    if hangle == 0 and input_model == 1:
        result2 = model.inference("GPT", db1 + " " + line)
    elif hangle == 0 and input_model == 2:
        result2 = model.inference("Gemini", db1 + " " + line)
    elif hangle == 0 and input_model == 3:
        result2 = model.inference("Llama", db1 + " " + line)
    elif hangle == 1 and input_model == 1:
        result2 = model.inference("Llama", db1 + " " + line)
    else:
        print("ERROR :: 유효하지 않은 입력입니다.")
        return

    if input1 < 1 or input1 > 3:
        print("ERROR :: 존재하지 않는 검색엔진입니다.")

    print("추론결과\n==============================")
    print(result2)
    print("Total Price : {}".format(price))

if __name__ == "__main__":
    main()
