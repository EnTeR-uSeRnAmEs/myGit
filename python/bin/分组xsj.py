from itertools import permutations
def sep(t,n):
    result_set,res = [],set()
    def foo(n,result=[]):
        if n==sum(result):
            sorted_result = sorted(result[:], reverse=True)
            if sorted_result not in result_set:
                result_set.append(sorted_result)
        else:
            for i in range(1,n):
                if sum(result)+i>n-i:
                    break
                result.append(i)
                foo(n-i,result)
                result.pop()
    foo(2*t)
    for i in result_set:
        if len(i)<=n:
            res|=set(permutations(i+[0]*(n-len(i))))
    return res

a = 0
for i in sep(4,4):
    a += 1
print(a)