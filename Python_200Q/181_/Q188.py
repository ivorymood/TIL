import pygame

BLACK = (0, 0, 0)
pad_width = 480
pad_height = 640

#게임 실행 메인 함수
def runGame():
    global gamepad, clock

    done_game = False
    while not done_game:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                done_game = True

        #게임화면을 검은색으로 채우고 화면 업데이트
        gamepad.fill(BLACK)
        pygame.display.update()
        clock.tick(60)

    pygame.quit()

#게임 초기화 함수
def initGame():
    global gamepad, clock

    pygame.init()
    gamepad = pygame.display.set_mode((pad_width, pad_height))
    pygame.display.set_caption('MyGalaga')
    clock = pygame.time.Clock()

initGame()
runGame()