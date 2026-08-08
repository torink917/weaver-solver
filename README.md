# weaver-solver
Solves a weaver puzzle in shortest path possible. 'Weaver' is a another name for the classic word ladder puzzle game. In this game you have a start word and end word both the same number of letters. Your goal is to get to the end word from the start word but only changing one word at a time. For instance if your start word is spat and end word is feud then one solution is this:
spat
seat
feat
feet
feed
feud

That's the solution my program finds and it is the shortest possible path.

In my program I utilize a tree data structure and a two sets. One set is for all possible eligible words. This way I have constant lookup time for words that actually exist. The other set is for words that I've already used in my tree so that I don't have an infinite tree.

The tree starts with the root word which is the same as the start word. It's an N-ary tree because the children are just all eligible words one letter away from the parent. I use breadth first search and stop when I find the target word. Once I find the target node I use that node to go all the way back up to the root so that I can print what the path was that got me to the target node.

My solution only returns one possible shortest path. However in many cases there could be many shortest path.

One problem with my program is that I don't have access to the exact list that Weaver used. So sometimes a have a word in MY word list that Weaver doesn't have in there word list. However 90% of the time the solution contains only words that Weaver also considers words.


