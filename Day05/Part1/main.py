with open(input("Filename >"), "r") as file:
    lines = file.readlines()

def compute_seed(seeds, numbers):
    computed = []
    changed = []

    for i in range(len(seeds)):
        changed.append(False)
        computed.append(seeds[i])

    for nbr in numbers:
        for j in range(len(seeds)):
            if (seeds[j] < nbr[1] + nbr[2]) and (seeds[j] >= nbr[1]):
                computed[j] = (seeds[j] - nbr[1]) + nbr[0]
                changed[j] = True

    for i in range(len(seeds)):
        if not changed[i]:
            computed[i] = seeds[i]

    return computed

def get_nearest(numbers):
    nearest = numbers[0]

    for i in range(len(numbers)):
        if numbers[i] < nearest:
            nearest = numbers[i]

    return nearest

seeds = []
seeds_computed = []

dic = {}

seeds_nums = lines[0].replace("\n", "").split(" ")
seeds_nums.pop(0)

for i in range(len(seeds_nums)):
    seeds.append(int(seeds_nums[i]))

lines.pop(0)
lines.pop(0)
lines.pop(0)

print("Seeds\t\t\t\t", seeds)

i = 0

nums = []
while lines[i] != "\n":
    nbrs = lines[i].replace("\n", "").split(" ")
    nums.append([int(nbrs[0]), int(nbrs[1]), int(nbrs[2])])
    i += 1

seeds_computed = compute_seed(seeds, nums)
print("Seeds computed for soil\t\t", seeds_computed)

i = i + 2

nums = []
while lines[i] != "\n":
    nbrs = lines[i].replace("\n", "").split(" ")
    nums.append([int(nbrs[0]), int(nbrs[1]), int(nbrs[2])])
    i += 1

seeds_computed = compute_seed(seeds_computed, nums)
print("Seeds computed for fertilizer\t", seeds_computed)

i = i + 2

nums = []
while lines[i] != "\n":
    nbrs = lines[i].replace("\n", "").split(" ")
    nums.append([int(nbrs[0]), int(nbrs[1]), int(nbrs[2])])
    i += 1

seeds_computed = compute_seed(seeds_computed, nums)
print("Seeds computed for water\t", seeds_computed)

i = i + 2

nums = []
while lines[i] != "\n":
    nbrs = lines[i].replace("\n", "").split(" ")
    nums.append([int(nbrs[0]), int(nbrs[1]), int(nbrs[2])])
    i += 1

seeds_computed = compute_seed(seeds_computed, nums)
print("Seeds computed for light\t", seeds_computed)

i = i + 2

nums = []
while lines[i] != "\n":
    nbrs = lines[i].replace("\n", "").split(" ")
    nums.append([int(nbrs[0]), int(nbrs[1]), int(nbrs[2])])
    i += 1

seeds_computed = compute_seed(seeds_computed, nums)
print("Seeds computed for temperature\t", seeds_computed)

i = i + 2

nums = []
while lines[i] != "\n":
    nbrs = lines[i].replace("\n", "").split(" ")
    nums.append([int(nbrs[0]), int(nbrs[1]), int(nbrs[2])])
    i += 1

seeds_computed = compute_seed(seeds_computed, nums)
print("Seeds computed for humidity\t", seeds_computed)

i = i + 2

nums = []
while i < len(lines):
    nbrs = lines[i].replace("\n", "").split(" ")
    nums.append([int(nbrs[0]), int(nbrs[1]), int(nbrs[2])])
    i += 1

seeds_computed = compute_seed(seeds_computed, nums)
print("Seeds computed for location\t", seeds_computed)

print("Nearest:", get_nearest(seeds_computed))