class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        # key is the ingredient, values are the recipes it can make
        graph = {}
        i = 0
        indegress = {}
        while i < len(recipes):
            recipe = recipes[i]
            ing = ingredients[i]
            for ig in ing:
                if ig not in graph:
                    graph[ig] = set()
                graph[ig].add(recipe)
                if recipe not in indegress:
                    indegress[recipe] = 0
                indegress[recipe] += 1
            i += 1
        q = supplies[::]
        answers = set()
        while q:
            ingredient = q.pop(0)
            if ingredient in recipes:
                answers.add(ingredient)
            for recipe in graph.get(ingredient, set()):
                indegress[recipe] -= 1
                if indegress[recipe] == 0:
                    q.append(recipe)
        return answers

