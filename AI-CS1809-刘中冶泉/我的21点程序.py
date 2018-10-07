 #coding:gbk
import random
class Card:
    def __init__(self,rank,suit):
        self.rank = rank
        self.suit = suit
class numCard(Card):
    def __init__(self,rank,suit):
        super().__init__(rank,suit)
        self.hard = self.soft = self.rank

class aceCard(Card):
    def __init__(self,rank,suit):
        super().__init__('A',suit)
        self.hard = 1
        self.soft = 11

class faceCard(Card):
    def __init__(self,rank,suit):
        super().__init__( rank , suit )
        self.hard = self.soft = 10

# somecard = [numCard('2','club'),aceCard('A','diamond'),faceCard('J','spade')]
# for i in somecard:
#     print( i.rank,i.suit,i.hard,i.soft)

"""--------------------------------------------- �ڶ����֣����ɶั��----------------------------------------------------
     һ����ΪDecks���б���Ԫ��Ϊһ������ """
def card4( rank, suit ):
    class_= {1: aceCard, 11: faceCard, 12: faceCard,13: faceCard}.get(rank, numCard)
    return class_( rank, suit ) 
class Decks(list):
    def __init__(self,num):
        super().__init__()
        for i in range(num):
            self.extend( card4(rank,suit) for rank in range(1,14) for suit in ['Club','Heart','Diamond','Spade'] )
        random.shuffle(self)

decks = Decks(3)
"""
     -----------------------------------------------�������֣�����--------------------------------------------------------
 """
class Hand:
    dieFlag = False
    def __init__(self,*mycards):
        self.mycards = []
        self.mycards.extend(mycards)
        print('�����ʼ��Ϊ: ',mycards[0].suit,mycards[0].rank,mycards[1].suit,mycards[1].rank)
        print('����������ܺ�Ϊ:',self.count())
 
    def askcard(self,acard):
        nowpoint = self.count()
        if Hand.dieFlag:
            print('������������ܺ�Ϊ ',nowpoint,'������')
        else:
            print('�����е�����:',acard.suit,acard.rank)
            self.mycards.append(acard)
            nowpoint = self.count()
            print('����������ܺ�Ϊ ',nowpoint)

    def count(self):
        sumpoint = sum( c.hard for c in self.mycards)
        if sumpoint > 21:
            sumpoint = sum( c.soft for c in self.mycards)
            if sumpoint > 21:
                Hand.dieFlag = True
        return sumpoint


if __name__=="__main__":
    hands = Hand(decks.pop(),decks.pop())
    while not hands.dieFlag:
        wt2askc = input('�ٴν��ƣ�<yes/no>: ')
        if wt2askc == 'yes' and not hands.dieFlag:
                hands.askcard(decks.pop())
        else:
            break
    print('���գ���õ��� %d ����'%hands.count())
