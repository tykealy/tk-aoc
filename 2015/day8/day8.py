with open("input.txt", "r") as file:
    lines = [line.strip().strip('') for line in file]

code = 0
character = 0
for line in lines:
    code += (len(line)+2)

decoded_lines = [bytes(line + " ", "utf-8").decode("unicode_escape").strip() for line in lines]

for dline in decoded_lines:
    character += len(dline)


print("Part1:", code - character )

new_code = 0 
code = 0
def decode_aoc_string(s):
    count = 0
    for i in range(len(s)):
        if s[i] == '"' or s[i] == '\\':
            count = count + 1  
    return count

for line in lines:
    code += (len(line))
    new_code += (len(line) + decode_aoc_string(line) + 2)

print("Part2:", new_code - code)
