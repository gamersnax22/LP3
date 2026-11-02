
import random

# Deterministic Quick Sort
def deterministicQuickSort(arr):

    stack = [(0, len(arr) - 1)]

    while stack:
        low, high = stack.pop()

        if low < high:
            pivot = arr[high]
            i = low - 1

            for j in range(low, high):
                if arr[j] <= pivot:
                    i += 1
                    arr[i], arr[j] = arr[j], arr[i]

            arr[i + 1], arr[high] = arr[high], arr[i + 1]
            p = i + 1

            stack.append((low, p - 1))
            stack.append((p + 1, high))

    return arr


# Randomized Quick Sort
def randomizedQuickSort(arr):

    stack = [(0, len(arr) - 1)]

    while stack:
        low, high = stack.pop()

        if low < high:
            r = random.randint(low, high)
            arr[r], arr[high] = arr[high], arr[r]

            pivot = arr[high]
            i = low - 1

            for j in range(low, high):
                if arr[j] <= pivot:
                    i += 1
                    arr[i], arr[j] = arr[j], arr[i]

            arr[i + 1], arr[high] = arr[high], arr[i + 1]
            p = i + 1

            stack.append((low, p - 1))
            stack.append((p + 1, high))

    return arr


# Main program
n = int(input("Enter number of elements: "))

arr = list(map(int, input("Enter elements: ").split()))

if len(arr) != n:
    print("Please enter exactly", n, "elements.")
else:
    result1 = deterministicQuickSort(arr.copy())
    print("Deterministic Quick Sort:", result1)

    result2 = randomizedQuickSort(arr.copy())
    print("Randomized Quick Sort:", result2)
