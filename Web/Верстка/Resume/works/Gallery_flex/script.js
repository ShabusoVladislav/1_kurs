const burger = document.querySelector('.burger'),
      nav = document.querySelector('.nav-links'),
      links = document.querySelectorAll('.nav-links li');

function slider() {
    burger.addEventListener('click', () => {

        nav.classList.toggle('nav-active');

        burger.classList.toggle('toggle');
    })
}

slider();