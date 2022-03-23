 # Find a path that explores all edges starting from JFK
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = {}
        ticket_counts = {}
        # build graph
        for ticket in tickets:
            if ticket[0] in graph:
                graph[ticket[0]].append(ticket[1])
            else:
                graph[ticket[0]] = [ticket[1]]
            
            if ticket[0] + '_' + ticket[1] in ticket_counts:
                ticket_counts[ticket[0] + '_' + ticket[1]] += 1
            else:
                ticket_counts[ticket[0] + '_' + ticket[1]] = 1
        for key in graph:
            graph[key].sort()
        total_edges = len(tickets)
        remaining_tickets = len(tickets)
        # dfs with backtracing
        results = []
        # hash the edge on whether it's visited
        # key is the edge, value is the ticket count, there could multiple tickets for an origin to a destination
        self.dfs(graph, 'JFK', ticket_counts, ['JFK'], results, remaining_tickets, total_edges)
        return results[0].split('_')
    
    def dfs(self, graph, from_city, ticket_counts, paths, results, remaining_tickets, total_edges):
        if len(paths) - 1 + remaining_tickets < total_edges:
            return
        if from_city in graph:
            for to_city in graph[from_city]:
                # If still tickets remaining
                if ticket_counts[from_city + '_' + to_city]:
                    ticket_counts[from_city + '_' + to_city] -= 1
                    remaining_tickets -= 1
                    paths.append(to_city)
                    if len(paths) - 1 == total_edges:
                        results.append('_'.join(paths))
                        return
                    self.dfs(graph, to_city, ticket_counts, paths, results, remaining_tickets, total_edges)
                    paths.pop()
                    ticket_counts[from_city + '_' + to_city] += 1
                    remaining_tickets += 1

