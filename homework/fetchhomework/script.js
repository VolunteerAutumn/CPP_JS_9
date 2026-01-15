// I used chatGPT for help cuz I'm sick rn and thinking for me is harder than it is normally
const usersList = document.getElementById("users");
const todosList = document.getElementById("todos");

fetch("https://jsonplaceholder.typicode.com/users")
    .then(response => response.json())
    .then(users => {
        users.forEach(user => {
            const li = document.createElement("li");
            li.textContent = user.name;
            li.onclick = () => loadTodos(user.id, user.name);
            usersList.appendChild(li);
        });
    })
    .catch(err => console.error(err));

function loadTodos(userId, userName) {
    todosList.innerHTML = `<h2>Справи: ${userName}</h2>`;

    fetch(`https://jsonplaceholder.typicode.com/todos?userId=${userId}`)
        .then(response => response.json())
        .then(todos => {
            todos.forEach(todo => {
                const li = document.createElement("li");
                li.textContent = todo.completed
                    ? `✅ ${todo.title}`
                    : `❌ ${todo.title}`;
                todosList.appendChild(li);
            });
        });
}
