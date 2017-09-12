def z(a, b):
    c = 0;
    if (a > b):
        c = z(b, a-1)
    else:
        c = a + b
    c = c + 1;
    return c

a = z(20, z(10, 2))
b = z(5, 0)
c = a + b + z(a,b)

print (a)
print (b)
print (c)


select id
from Payment
where (
  select count(*)
  from BackgroundJob
  where BackgroundJob.id = Payment.id and BackgroundJob.pending = 'T'
) = 0;
