function f0(x)				! подынтегральная функция
implicit none
real(8) x, f0
	f0 = x**3
end function

function f1(x)				! подынтегральная функция
implicit none
real(8) x, f1
	f1 = sin(x)
end function



function sim(f, a, b, n)			! Метод Симпсона
!implicit none
integer i,n
real(8) a, b, f, sim, h, s1, s2, x
h = (b-a)/n
s1 = 0
s2 = 0
	do i = 0, n-1
    	x = a + i*h
    		if (mod(i,2) == 0) then
        		s1 = s1 + f(x)
    		else
        		s2 = s2 + f(x)
    		endif
	enddo
sim = (h/3) * (f(a) + f(b) + 4*s1 + 2*s2)
end function sim



function rect(f, a, b, n)		!прямоугольник
implicit none
interface
	function f(x)				! подынтегральная функция
		implicit none
		real(8) x, f
	end function
end interface
integer n, i
real(8) a, b, rect, h, x
h = (b-a)/real(n, 8)
rect = 0
	do i = 1, n
	    x = a + (i-0.5)*h
	    rect = rect + f(x)
	enddo
rect = rect*h
end function rect



function trap(f, a, b, n)		! трапеция
implicit none
integer n, i
real(8) a, b, f, trap, h, s, x
h = (b-a)/n
s = (f(a) + f(b))/2
	do i = 2, n
	    x = a + (i-1)*h
	    s = s + f(x)
	enddo
trap = s*h
end function trap

