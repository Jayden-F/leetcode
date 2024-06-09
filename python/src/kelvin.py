def perm_is_palindrome(string: str) -> bool:
    bit_set = 0
    length = len(string)

    for i in range(length):
        bit_set ^= 1 << ord(string[i])

    return ((length & 1) and not (bit_set & bit_set - 1)) or (
        not (length & 1) and not bit_set
    )


assert perm_is_palindrome("racecar")
assert perm_is_palindrome("zenzone")
assert not perm_is_palindrome("false")
assert perm_is_palindrome("1")
assert perm_is_palindrome("")
assert perm_is_palindrome("poop")
assert perm_is_palindrome("poopp")
assert not perm_is_palindrome("segments")
