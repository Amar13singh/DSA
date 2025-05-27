document.addEventListener("DOMContentLoaded", () => {
  const wrapper = document.querySelector(".wrapper");
  const loginLink = document.querySelector(".login-link");
  const registerLink = document.querySelector(".register-link");
  const btnPopup = document.querySelector(".btnLogin-popup");
  const iconClose = document.querySelector(".icon-close");
  const dropBtn = document.querySelector(".dropbtn");
  const submenu = document.querySelector(".submenu");

  registerLink.addEventListener('click', () => {
  wrapper.classList.add('active-popup');
  document.querySelector('.form-box.login').classList.remove('active');
  document.querySelector('.form-box.register').classList.add('active');
});

loginLink.addEventListener('click', () => {
  wrapper.classList.add('active-popup');
  document.querySelector('.form-box.register').classList.remove('active');
  document.querySelector('.form-box.login').classList.add('active');
});

btnPopup.addEventListener('click', () => {
  wrapper.classList.add('active-popup');
  document.querySelector('.form-box.login').classList.add('active');
  document.querySelector('.form-box.register').classList.remove('active');
  document.body.classList.add('popup-open');  // for overlay

});

iconClose.addEventListener('click', () => {
  wrapper.classList.remove('active-popup');
  document.body.classList.remove('popup-open');  // remove overlay
});

  // Dropdown menu toggle
  dropBtn.addEventListener("click", () => {
    submenu.classList.toggle("show");
  });

  // Optional: close dropdown if clicked outside
  window.addEventListener("click", (e) => {
    if (!dropBtn.contains(e.target) && !submenu.contains(e.target)) {
      submenu.classList.remove("show");
    }
  });

  const menuToggle = document.getElementById('menu-toggle');
const navigation = document.querySelector('.navigation');

menuToggle.addEventListener('click', () => {
  navigation.classList.toggle('active');

  // Change icon between menu and close
  const icon = menuToggle.querySelector('ion-icon');
  const isMenu = icon.name === 'menu-outline';
  icon.name = isMenu ? 'close-outline' : 'menu-outline';
});

});
