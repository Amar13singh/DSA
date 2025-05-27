// Show popup when login button is clicked
const loginPopup = document.querySelector(".wrapper");
const loginBtn = document.querySelector(".btnLogin-popup");
const closeBtn = document.querySelector("#closeBtn");

loginBtn.addEventListener("click", () => {
  loginPopup.classList.add("active-popup");
});

closeBtn.addEventListener("click", () => {
  loginPopup.classList.remove("active-popup");
});

// Nav link active toggle
const navLinks = document.querySelectorAll(".nav-link");
navLinks.forEach(link => {
  link.addEventListener("click", () => {
    navLinks.forEach(l => l.classList.remove("active"));
    link.classList.add("active");
  });
});
