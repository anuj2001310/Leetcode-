class Solution:
    def numRabbits(self, answers: List[int]) -> int:

        aggregeted_answers = Counter(answers)

        print(aggregeted_answers)

        minimal_rabbit_amount = 0

        for answers_type, answers_popularity in aggregeted_answers.items():

            if answers_popularity % (answers_type + 1) == 0:
                minimal_rabbit_amount += answers_popularity

            else:
                minimal_rabbit_amount += ceil(answers_popularity/(answers_type + 1)) * (answers_type + 1)

        return minimal_rabbit_amount
        