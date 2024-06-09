from typing import List


def findMin(nums: List[int]) -> int:
    low = 0
    high = len(nums) - 1

    while low < high:
        mid = low + (high - low) // 2
        print(low, mid, high)

        if nums[mid] < nums[high]:
            low = mid + 1
        else:
            high = mid

    print(low)
    return nums[low]


if __name__ == "__main__":
    assert findMin([1, 2, 3, 4, 5]) == 5
    assert findMin([4, 5, 1, 2, 3]) == 1
