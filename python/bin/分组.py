import itertools
result_set = [] 
result_return = [] 
def foo(n, result=[]):
    if n == sum(result):
        sorted_result = sorted(result[:], reverse=True)
        if sorted_result not in result_set:
            result_set.append(sorted_result)
    else:
        for i in range(1, n):
            if sum(result) + i > n - i:
                break
            result.append(i)
            foo(n - i, result)
            result.pop()
def combination_sum(n):
    foo(2 * n)
    return result_set
def f(t,n):
    res=sorted(combination_sum(t))
    for i in res:
        if len(i)<=n:
            for k in range(n-len(i)) :
                i.append(0)
            result_return.append(i)
    for i in result_return:
        a=list(itertools.permutations(i))
        for x in a:
            if not(list(x) in result_return):
                result_return.append(list(x))
    return result_return   