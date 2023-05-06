import sys, math

# Author: Brody Liudzius

# Written: 2-2-2022
# Revised: 5-5-2023
# - Rewrote in Python (was C++)
# - Revised hkl values 

angles:list[float]

# Multiples to use
numsToTry:list[float] = [1,2,3,4,5,6]

# Values of h^2+k^2+l^2 for different lattice structures
SC: list[float] = [1,2,3,4,5,6,8,9,10,11,12,13,14,16,17,18,19,20,21,22,24,25,26,27,29,34]
BCC: list[float] = [2,4,6,8,10,12,14,16,18,20,22,24,26,34]
FCC: list[float] = [3,4,8,11,12,16,19,20,24,27,32]

SCDiffs: list[float] = []
BCCDiffs: list[float] = []
FCCDiffs: list[float] = []

def Closest(_n:float, _arr:list[float]):
    if _n > 30:
        return 0
    best:float = 0
    lowestDiff:float = float("inf")
    for i in _arr:
        diff:float = abs(_n-1)
        if diff < lowestDiff:
            lowestDiff = diff
            best = i
    return best

# Retreive angles from file
if len(sys.argv) >= 2:
    with open(sys.argv[1]) as file:
        angles = [float(line) for line in file]
else:
    print("Please provide input data.\n")
    quit()

# Get sin^2 of angles
for i in range(len(angles)):
    angles[i] = math.pow(math.sin(angles[i]*0.0174533), 2.0)

# Sort the list
angles.sort()

# Scale all angles by the smallest angle
smallest:float = angles[0]
for i in range(len(angles)):
    angles[i] /= smallest

# Generate numbers multiplied by a multiple,
# calculate diff from closest in a set and use total diff
for k in numsToTry:
    totalDiffSC:float = 0
    totalDiffBCC:float = 0
    totalDiffFCC:float = 0

    for a in angles:
        c:float = Closest(a*k, SC)
        if c == 0:
            continue
        totalDiffSC += abs(a*k-c)
    for a in angles:
        c:float = Closest(a*k, BCC)
        if c == 0:
            continue
        totalDiffBCC += abs(a*k-c)
    for a in angles:
        c:float = Closest(a*k, FCC)
        if c == 0:
            continue
        totalDiffFCC += abs(a*k-c)
    SCDiffs.append(totalDiffSC)
    BCCDiffs.append(totalDiffBCC)
    FCCDiffs.append(totalDiffFCC)

smallestSCDiff:float = float("inf")
for d in SCDiffs:
    if d < smallestSCDiff:
        smallestSCDiff = d
smallestBCCDiff:float = float("inf")
for d in BCCDiffs:
    if d < smallestBCCDiff:
        smallestBCCDiff = d
smallestFCCDiff:float = float("inf")
for d in FCCDiffs:
    if d < smallestFCCDiff:
        smallestFCCDiff = d

print("SC Diffs:")
for i in range(len(numsToTry)):
    print(("*" if SCDiffs[i] == smallestSCDiff else " ") + str(i+1) + ": " + str(SCDiffs[i]))
print("BCC Diffs:")
for i in range(len(numsToTry)):
    print(("*" if BCCDiffs[i] == smallestBCCDiff else " ") + str(i+1) + ": " + str(BCCDiffs[i]))
print("FCC Diffs:")
for i in range(len(numsToTry)):
    print(("*" if FCCDiffs[i] == smallestFCCDiff else " ") + str(i+1) + ": " + str(FCCDiffs[i]))