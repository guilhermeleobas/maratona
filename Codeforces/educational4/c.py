
class stack:
    def __init__ (self):
        self.data = [];
    
    def push (self, e):
        return self.data.append (e);
    
    def pop (self):
        return self.data.pop();
    
    def empty (self):
        return len(self.data) == 0;
    
    def top (self):
        return self.data[len(self.data) - 1];

if __name__ == "__main__":
    s = raw_input()
    p = stack();
    status = True;
    cnt = 0;
    
    for i in s:
        if (i == '[' or i == '{' or i == '<' or i == '('):
            p.push (i);
        else:
            if p.empty():
                status = False;
                break;
            
            e = p.top();
            p.pop();
            if ((e == '[' and i == ']') or (e == '(' and i == ')') or (e == '<' and i == '>') or (e == '{' and i == '}') ):
                continue;
            else:
                cnt += 1;
    
    if status == False or p.empty() == False:
        print "Impossible";
    else:
        print cnt;
