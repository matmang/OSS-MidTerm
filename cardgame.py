def fresh_deck():
    suits = {"Spade", "Heart", "Diamond", "Club"}
    ranks = {2, 3, 4, 5, 6, 7, 8, 9, 10, "J", "Q", "K", "A"}
    deck = []
    for suit in suits:
        for rank in ranks:
            card = (suit, rank)
            deck.append(card)
        import random
        random.shuffle(deck)
        return deck

def hit(deck):
    if deck == []:
        deck = fresh_deck()
    return (deck[0], deck[1:])

def count_score(cards):
    score = 0
    number_of_ace = 0
    for card in cards:
        rank = card[1]
        if rank == "J" or rank == "Q" or rank == "K":
            score += 10
        elif rank == "A":
            score += 11
            number_of_ace += 1
        else:
            score += rank
    while score > 21 and number_of_ace > 0:
        score -= 10
        number_of_ace -= 1
    return score

def show_cards(cards, message):
    print(message)
    for card in cards:
        print(' ', card[0], card[1])

def more(message):
    answer = input(message)
    while not (answer == 'y' or answer == 'n'):
        answer = input(message)
    return answer == 'y'

def load_members():
    file = open("members.txt", 'r')
    members = {}
    for line in file:
        name, passwd, tries, wins, chips = line.strip('\n').split(',')
        members[name] = (passwd, int(tries), float(wins), int(chips))
        file.close()
        return members

def store_members(members):
    file = open('members.txt', 'w')
    names = members.keys()
    for name in names:
        passwd, tries, wins, chips = members[name]
        line = name + ',' + passwd + ',' +\
               str(tries) + ',' + str(wins) + ',' + str(chips) + '\n'
        file.write(line)
    file.close()

def safe_divide(x,y):
    return x/y if y > 0 else 0

def login(members):
    username = input("Enter your name: (4 letters max) ")
    while len(username) > 4:
        username = input("Enter your name: (4 letters max) ")
    trypasswd = input("Enter your password: ")
    if username in members:
        (passwd, tries, wins, chips) = members[username]
        if passwd == trypasswd:
            print('you played', tries, 'games and won', int(wins), 'of them.')
            win_pct = safe_divide(wins, tries)
            print('Your all-time winning percentage is', round(win_pct, 2), '%')
            if chips < 0:
                print('You owe', chips, 'chips.')
            if chips >= 0:
                print('You have', chips, 'chips.')
            return username, tries, wins, chips, members
        else:
            return login(members)
    else:
        members[username]